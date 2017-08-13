//
// Created by Qiang Chen on 12/08/2017.
//
//
//　　对于序列S和T，求它们的最长公共子序列。例如X={A,B,C,B,D,A,B}，Y={B,D,C,A,B,A}则它们的lcs是{B,C,B,A}和{B,D,A,B}。求出一个即可。
//
//解法：
//
//　　和2类似，对于X[1...m]和Y[1...n]，它们的任意一个lcs是Z[1...k]。
//
//　　(1)如果X[m]=Y[n]，那么Z[k]=X[m]=Y[n],且Z[1...k-1]是X[1...m-1]和Y[1...n-1]的一个lcs；
//
//　　(2)如果X[m]!=Y[n]，那么Z[k]!=X[m]时Z是X[1...m-1]和Y的一个lcs；
//
//　　(3)如果X[m]!=Y[n]，那么Z[k]!=Y[n]时Z是X和Y[1...n-1]的一个lcs；


#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Exer2_LongestCommonSubsequence {

public:
    vector<string> longestCommonSubsequence(string &s1, string &s2 ) {
        int m = s1.length();
        int n = s2.length();
        s1.insert(0, 1, '0');
        s2.insert(0, 1, '0');

        int ** lenT = new int *[m + 1];
        int ** resourceT = new int *[m + 1];
        for (int i = 0; i < m + 1; ++i) {
            lenT[i] = new int[n + 1];
            resourceT[i] = new int[n + 1];
        }

        for (int j = 0; j < m + 1; ++j) {
            lenT[0][j] = 0;
            resourceT[0][j] = LEFT;
        }
        for (int k = 0; k < n + 1; ++k) {
            lenT[k][0] = 0;
            resourceT[k][0] = UP;
        }

        for (int r = 1; r < m + 1; ++r) {
            for (int s = 1; s < n + 1; ++s) {
                if(s1[r] == s2[s]) {
                    lenT[r][s] = lenT[r - 1][s - 1] + 1;
                    resourceT[r][s] = LEFT_UP;
                } else if (lenT[r - 1][s] == lenT[r][s - 1]) {
                    lenT[r][s] = lenT[r][s - 1];
                    resourceT[r][s] = BOTH_UP_AND_LEFT;
                } else if (lenT[r - 1][s] < lenT[r][s - 1]) {
                    lenT[r][s] = lenT[r][s - 1];
                    resourceT[r][s] = LEFT;
                } else {
                    lenT[r][s] = lenT[r - 1][s];
                    resourceT[r][s] = UP;
                }
            }
        }


        vector<string> result;
        string* temp = new string;
        this->getStringFromTable(s1, s2, m, n, resourceT, temp, result);

        for (int l = 0; l < m + 1; ++l) {
            delete[] resourceT[l];
            delete[] lenT[l];
        }
        return result;
    }


private:
    static const int LEFT_UP = 0;
    static const int LEFT = 1;
    static const int UP = 2;
    static const int BOTH_UP_AND_LEFT = 3;
    void getStringFromTable(string &s1, string &s2, int r, int s, int ** resourceT, string* tempStr, vector<string> &result) {

        while ( r != 0 && s != 0 ) {
            if(s1[r] == s2[s]) {
                tempStr->insert(0, 1, s1[r]);
                r--;
                s--;
            } else {
                switch(resourceT[r][s])  {
                    case LEFT:
                        s--;
                        break;
                    case UP:
                        r--;
                        break;
                    case BOTH_UP_AND_LEFT:
                        getStringFromTable(s1, s2, r - 1, s, resourceT, new string(*tempStr), result);
                        getStringFromTable(s1, s2, r, s - 1, resourceT, new string(*tempStr), result);
                        return;
                    default:
                        // do nothing
                        break;
                }
            }
        }

        if (tempStr->length()) {
            result.push_back(*tempStr);
            delete tempStr;
        }



    }

//    　　通过LCS获得最长递增自子序列。
//
//    分析：
//
//    　　对于1个序列，如243517698，最大值9，最小值1，那么通过将它与123456789求LCS得到的就是最长连续递增子序列23568。
//
//    　　这种做法不适用于最长连续非递减子序列，除非能获得重复最多的元素数目，如2433517698，那么可以用112233445566778899与之比较。

};