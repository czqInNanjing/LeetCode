//
// Created by Qiang Chen on 13/08/2017.
//
//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?

//可以压缩存储空间为O(n)，参见背包算法
class No62_UniquePaths {
public:
    int uniquePaths2(int m, int n) {
        int grids[n];
        for (int i = 0; i < n; ++i) {
            grids[i] = 1;
        }

        for (int j = 1; j < m; ++j) {
            for (int k = 1; k < n; ++k) {
                grids[k] += grids[k - 1];
            }
        }



        return grids[n - 1];

    }


    int uniquePaths(int m, int n) {
        int ** grids = new int *[m];
        for (int i = 0; i < m; ++i) {
            grids[i] = new int [n];
        }

        grids[0][0] = 1;
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if( j != 0 || k != 0 )
                    grids[j][k] = 0;
                if(j != 0) {
                    grids[j][k] += grids[j - 1][k];
                }
                if(k != 0) {
                    grids[j][k] += grids[j][k - 1];
                }
            }
        }
        int result = grids[m - 1][n - 1];
        for (int i = 0; i < m; ++i) {
            delete[] grids[i];
        }

        return result;

    }
};