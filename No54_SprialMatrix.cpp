//
// Created by Qiang Chen on 27/07/2017.
//
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//        Given the following matrix:
//
//[
//[ 1, 2, 3 ],
//[ 4, 5, 6 ],
//[ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].


#include "vector"
#include "iostream"
#include "cmath"
using namespace std;
using std::vector;

class No54_SprialMatrix {
public:
    void printFromRightToDown(int startLoop, vector<vector<int>> &vector1, vector<int> *result) {
        long finalPosition = vector1.size() - startLoop;
        long readCount = vector1[0].size() - startLoop - 1;
        for (int i = startLoop + 1; i < finalPosition; ++i) {
            result->push_back(vector1[i][readCount]);
        }
    }

    void printFromDownToUp(int startLoop, vector<vector<int>> &vector1, vector<int> *result){
        long y = startLoop;
        long xStart = vector1.size() - startLoop - 2;
        long xFinal = y == (vector1[0].size() - startLoop - 1) ? startLoop + 2 : startLoop + 1;
        for (int i = xStart; i >= xFinal ; --i) {
            result->push_back(vector1[i][y]);
        }
    }
    void printFromRightToLeft(int startLoop, vector <vector<int>> &vector1, vector<int> *result) {
        long x = vector1.size() - startLoop - 1;
        long yStart = vector1[0].size() - startLoop - 2;
        long yFinal = x == startLoop ? startLoop + 1 : startLoop;

//        cout << yStart << " " << yFinal << " " << x;
//        cout << endl;
        for (int i = yStart; i >= yFinal ; --i) {
            result->push_back(vector1[x][i]);
        }

    }

    void printFromLeftToRight(int startLoop, vector<vector<int>> &vector1, vector<int>* result) {

        std::vector<int> lineN = vector1[startLoop];
        long finalPosition = lineN.size() - startLoop;
        for (int i = startLoop; i < finalPosition; ++i) {
            result->push_back(lineN[i]);
        }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix) {

        long m = matrix.size();

        if(m == 0)
            return vector<int>();

        long n = matrix.at(0).size();

        if(n == 0)
            return vector<int>();

        vector<int> result = vector<int>();

        if (m == 1)
            return matrix[0];
        if (n == 1) {

            for (int i = 0; i < m; ++i) {
                result.push_back(matrix[i][0]);
            }
            return result;
        }

        long loopTimes = min(ceil(m/2.0), ceil(n/2.0));

        for (int j = 0; j < loopTimes; ++j) {

            printFromLeftToRight(j, matrix, &result);

            printFromRightToDown(j, matrix, &result);

            printFromRightToLeft(j, matrix, &result);

            printFromDownToUp(j, matrix, &result);

        }

        return result;
    }
};














