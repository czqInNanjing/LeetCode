//
// Created by Qiang Chen on 29/07/2017.
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4-queens puzzle:
//
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]


#include <iostream>
#include "vector"
#include "string"
#include "cmath"

using namespace std;


class No51_NQueens {
public:


    bool checkIfAvailable(int **boards, int n, int queenNum) {
        if (queenNum == 1)
            return true;

        // find the queens column index (not need to find their row index)
        int queenColumns[queenNum];

        for (int i = 0; i < queenNum; ++i) {
            for (int j = 0; j < n; ++j) {
                if (boards[i][j] == 1) {
                    queenColumns[i] = j;
                    break;
                }
            }
        }

        int lastIndex = queenColumns[queenNum - 1];
        // in fact, we only need to check whether the last queen is qualified, all the other queens has been check

        for (int k = 0; k < queenNum - 1; ++k) {
            // check if they are in the same columns
            if (lastIndex == queenColumns[k])
                return false;

            // check if they are on the diagonal

            if (fabs(fabs(lastIndex - queenColumns[k]) - fabs(queenNum - 1 - k)) < 0.0001)
                return false;
        }


        return true;
    }

    void putNextQueens(int **boards, int n, int row, int column, vector<vector<string>> *result) {

        if (row == n) {
            if (checkIfAvailable(boards, n, row)) {
                vector<string> tempResult;
                for (int i = 0; i < n; ++i) {
                    string tempLine = "";
                    for (int j = 0; j < n; ++j) {

                        // 这里巨坑，一开始忘记初始化导致随机数都设置为Q了。。。。。。
                        //源代码 tempLine += boards[i][j] == 0 ? "." : "Q";
                        tempLine += boards[i][j] == 1 ? "Q" : ".";
                    }
                    tempResult.push_back(tempLine);
                }



                result->push_back(tempResult);
            }
            return;
        }




        boards[row][column] = 1;
        if (checkIfAvailable(boards, n, row + 1)) { // the current situation is possible, continue deep search
            putNextQueens(boards, n, row + 1, 0, result);
        }
        boards[row][column] = 0;
        if ( column != n - 1 ) {
            putNextQueens(boards, n, row, column + 1, result);
        }



    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        int **boards = new int *[n];
        for (int l = 0; l < n; ++l) {
            boards[l] = new int[n];
        }
        //start to find result from [0, 0]
        putNextQueens(boards, n, 0, 0, &result);


        for (int m = 0; m < n; ++m) {
            delete[] boards[m];
        }


        return result;

    }


};