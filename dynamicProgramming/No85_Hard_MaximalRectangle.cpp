//
// Created by Qiang Chen on 8/14/17.
//

//https://leetcode.com/problems/maximal-rectangle/description/
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 6.

#include <vector>
using namespace std;



class No85_Hard_MaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        INT_MIN
    }



    /**
     * 思路错误，但是还是觉得写的不错的代码，思路清晰，未使用IDE，值得褒奖
     */
//    int maximalRectangle(vector<vector<char>>& matrix) {
//        if( matrix.size() == 0 || matrix[0].size() == 0)
//            return 0;
//        int max = 0;
//        // maxRectangle ends at this point
//        int maxX[matrix.size()][matrix[0].size()];
//        int maxY[matrix.size()][matrix[0].size()];
//        for ( int i = 0 ; i < matrix.size() ; ++i ) {
//            for( int j = 0 ; j < matrix[0].size() ; ++j ) {
//                if(matrix[i][j] == '1') {
//                    int tempMaxX = 1;
//                    int tempMaxY = 1;
//                    int topTempMaxX = 1;
//                    int topTempMaxY = 1;
//                    if( i != 0 ) {
//                        int topX = maxX[i - 1][j];
//                        int topY = maxY[i - 1][j];
//                        int newX = 0;
//                        if ( topX != 0 && topY != 0 ) {
//                            for( int tempY = j - 1 ; tempY > j - topX ; tempY-- ) {
//                                if(matrix[i][tempY] == '1') {
//                                    newX++;
//                                } else {
//                                    break;
//                                }
//                            }
//                            tempMaxX = newX + 1;
//                            tempMaxY = topY + 1;
//                        }
//                    }
//
//                    if ( j != 0 ) {
//                        int leftX = maxX[i][j - 1];
//                        int leftY = maxY[i][j - 1];
//                        int newY = 0;
//                        if ( leftX != 0 && leftY != 0 ) {
//                            for ( int tempX = i - 1 ; tempX > i - leftY ; tempX-- ) {
//                                if(matrix[tempX][j] == '1') {
//                                    newY++;
//                                } else {
//                                    break;
//                                }
//                            }
//                            topTempMaxX = leftX + 1;
//                            topTempMaxY = newY + 1;
//
//                        }
//                    }
//
//                    if (topTempMaxY* topTempMaxX > tempMaxX*tempMaxY) {
//                        maxX[i][j] = topTempMaxX;
//                        maxY[i][j] = topTempMaxY;
//                    } else {
//                        maxX[i][j] = tempMaxX;
//                        maxY[i][j] = tempMaxY;
//                    }
//                    max = max >  maxX[i][j]*maxY[i][j] ? max : maxX[i][j]*maxY[i][j];
//
//                } else {
//                    maxX[i][j] = 0;
//                    maxY[i][j] = 0;
//                }
//
//
//
//            }
//        }
//
//        return max;
//
//    }
};