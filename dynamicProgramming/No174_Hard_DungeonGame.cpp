//
// Created by Qiang Chen on 11/09/2017.
//
#include <vector>
#include <map>
/*
 * 这道题是No62,63,64的变种
 * 可以观察归纳出几个特性：
 * 1. 这道题如果从左上角开始的话有一个问题就是： 骑士的起始血未知，无法进行状态转移。从右下角开始则不存在这个问题
 * 2. 从左上角开始的话一般会在左边和上面增加一个dummy行列，从右下角开始的话在右边和下面增加一个dummy行列
 */
using namespace std;
class No174_Hard_DungeonGame{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
        hp[m - 1][n] = hp[m][n - 1] = 1;

        for(int i = m - 1; i >= 0; --i ) {
            for(int j = n - 1; j >=0; --j ) {
                if(dungeon[i][j] >= 0 ) {
                    int temp = dungeon[i][j] - min(hp[i + 1][j], hp[i][j + 1]);
                    if(temp >= 0) hp[i][j] = 1;
                    else hp[i][j] = - temp;
                }
                else hp[i][j] = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
            }
        }
        return hp[0][0];
    }
};
