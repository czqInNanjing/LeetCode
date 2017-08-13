//
// Created by Qiang Chen on 13/08/2017.
//

//Given a m x n grid filled with non-negative numbers,
// find a path from top left to bottom right which minimizes the sum of all numbers
// along its path.
//
//Note: You can only move either down or right at any point in time.




#include <vector>

using namespace std;
class No64_MinimumPathNums {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> result;
        vector<int> tempResult;
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 0 ; i < m ; i++ ) {
            if ( i == 0 ) {
                tempResult.push_back(grid[i][0]);
            } else {
                tempResult.push_back(grid[i][0] + result[i - 1][0]);
            }
            result.push_back(tempResult);
            tempResult.clear();
        }
        for( int i = 1 ; i < n ; i++ ) {
            result[0].push_back(grid[0][i] + result[0][i - 1]);
        }


        for ( int i = 1 ; i < m ; i++ ) {
            for ( int j = 1 ; j < n ; j ++ ) {
                int min = result[i - 1][j] < result[i][j - 1] ? result[i - 1][j] : result[i][j - 1];
                result[i].push_back(min + grid[i][j]);

            }
        }
        return result[m - 1][n - 1];
    }
};
