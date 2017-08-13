//
// Created by Qiang Chen on 13/08/2017.
//
//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//        There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//[0,0,0],
//[0,1,0],
//[0,0,0]
//]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.

// 没啥区别，就是极端情况考虑的多了一点
#include <vector>
using namespace std;
class No62_UniquePaths2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int grids[n];
        grids[0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < n; ++i) {
            grids[i] = 0;
            if(!obstacleGrid[0][i]) {
                grids[i] += grids[i - 1];
            }
        }

        for (int j = 1; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if(obstacleGrid[j][k]) {
                    grids[k] = 0;
                } else {
                    if(k != 0)
                        grids[k] += grids[k - 1];
                }

            }
        }



        return grids[n - 1];
    }
};