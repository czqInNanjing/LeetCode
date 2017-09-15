//
// Created by Qiang Chen on 8/11/17.
//

//　　对于序列S和T，它们之间距离定义为：对二者其一进行几次以下的操作(1)删去一个字符；(2)插入一个字符；(3)改变一个字符。每进行一次操作，计数增加1。将S和T变为同一个字符串的最小计数即为它们的距离。给出相应算法。
//
//解法：
//
//　　将S和T的长度分别记为len(S)和len(T)，并把S和T的距离记为m[len(S)][len(T)]，有以下几种情况：
//
//如果末尾字符相同，那么m[len(S)][len(T)]=m[len(S)-1][len(T)-1]；
//
//如果末尾字符不同，有以下处理方式
//
//　　修改S或T末尾字符使其与另一个一致来完成，m[len(S)][len(T)]=m[len(S)-1][len(T)-1]+1；
//
//　　在S末尾插入T末尾的字符，比较S[1...len(S)]和S[1...len(T)-1]；
//
//　　在T末尾插入S末尾的字符，比较S[1...len(S)-1]和S[1...len(T)]；
//
//　　删除S末尾的字符，比较S[1...len(S)-1]和S[1...len(T)]；
//
//　　删除T末尾的字符，比较S[1...len(S)]和S[1...len(T)-1]；
//
//　　总结为，对于i>0,j>0的状态(i,j),m[i][j] = min( m[i-1][j-1]+(s[i]==s[j])?0:1 , m[i-1][j]+1, m[i][j-1] +1)。
//
//　　这里的重叠子结构是S[1...i]，T[1...j]。



#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 这道题是  编辑距离 题目的完整题型，使用了动态规划的思想
//  string erase 会影响自己本身
// 这道题的一个难点是一个打印转换过程，难度主要在于你只能记录每一步的过程，回溯的时候要理解是对应的字符做相应的修改
// 动态数组记得回收内存

class Exer1_DistanceBetweenTwoString {
public:
    static const int INSERT = 0;
    static const int DELETE = 1;
    static const int CHANGE = 2;
    static const int NO_OPERATION = 3;
    int distanceBetweenStrings(string& s1, string& s2, vector<string>& changeWay) {
        const int m = s1.length();
        const int n = s2.length();
        int ** timesArray = new int*[m + 1];
        int ** operationArray = new int*[m + 1];

        for (int j = 0; j < m + 1; ++j) {
            timesArray[j] = new int[n + 1];
            operationArray[j] = new int[n + 1];
        }

        timesArray[0][0] = 0;
        operationArray[0][0] = NO_OPERATION;

        for (int k = 1; k < m + 1; ++k) {
            timesArray[k][0] = k;
            operationArray[k][0] = DELETE;
        }
        for (int l = 1; l < n + 1; ++l) {
            timesArray[0][l] = l;
            operationArray[0][l] = INSERT;
        }

        s1 = s1.insert(0, "0");
        s2 = s2.insert(0, "0");
        int tempResult[3];
        int options[] = {DELETE, INSERT, CHANGE, NO_OPERATION};
        for (int r = 1; r < m + 1; ++r) {
            for (int s = 1; s < n + 1; ++s) {
                int d = s1[r] == s2[s] ? 0 : 1;
                timesArray[r][s] = tempResult[0] = timesArray[r - 1][s] + 1;
                               operationArray[r][s] = options[0];
                tempResult[1] = timesArray[r][s - 1] + 1;
                tempResult[2] = timesArray[r - 1][s - 1] + d;

                for (int i = 1; i < 3; ++i) {
                    if (timesArray[r][s] > tempResult[i]) {
                        timesArray[r][s] = tempResult[i];
                        operationArray[r][s] = options[i];
                    }
                }
                if (operationArray[r][s] == CHANGE && d == 0) {
                    operationArray[r][s] = NO_OPERATION;
                }


            }
        }

        int indexX = m;
        int indexY = n;
        string temps(s2);
        vector<string> tempChangeWay;
        while ( indexX != 0 || indexY != 0 ) {
            switch (operationArray[indexX][indexY]) {
                case NO_OPERATION:
                    indexX--;
                    indexY--;
                    break;
                case CHANGE:
                    temps[indexY] = s1[indexX];
                    tempChangeWay.push_back(temps.substr(1));
                    indexX--;
                    indexY--;
                    break;
                case INSERT:
                    temps.erase(indexY, 1);
                    indexY--;
                    tempChangeWay.push_back(temps.substr(1));
                    break;
                case DELETE:
                    temps.insert(indexY + 1, s1.substr(indexX, 1));
                    indexX--;
                    tempChangeWay.push_back(temps.substr(1));
                    break;
                default:
                    // do nothing
                    break;
            }
        }

        for (vector<string>::reverse_iterator start =  tempChangeWay.rbegin(); start != tempChangeWay.rend() ; start++ ) {
            changeWay.push_back(*start);
        }
        s2.erase(0, 1);
        changeWay.push_back(s2);

        int result = timesArray[m][n];

        for (int i1 = 0; i1 < m + 1; ++i1) {
            delete[] timesArray[i1];
            delete[] operationArray[i1];
        }
        return result;

    }


};