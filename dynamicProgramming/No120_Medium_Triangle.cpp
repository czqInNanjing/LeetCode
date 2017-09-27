//
// Created by Qiang Chen on 05/09/2017
//
// 很容易的一道题，记录它只是因为beat 99.14%的人！！！！！！！！！！！令人高兴
#include <vector>
using namespace std;
class No120_Medium_Triangle{
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;

        vector<int> dp(triangle.back().back());

        int r = triangle.size();
        for(int i = r - 2; i >= 0 ; --i) {
            for(int j = 0 ; j < i + 1; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];



    }
};