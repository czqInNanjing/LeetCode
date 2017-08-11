//
// Created by Qiang Chen on 8/11/17.
//



#include <string>
#include <vector>
using namespace std;


class Exer1_DistanceBetweenTwoString {
public:
    static const int INSERT = 0;
    static const int DELETE = 1;
    static const int CHANGE = 2;
    static const int NO_OPERATION = 3;
    int distanceBetweenStrings(string& s1, string& s2, vector<string>& changeWay) {
        int m = s1.length();
        int n = s2.length();
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
        int options[] = {INSERT, DELETE, CHANGE, NO_OPERATION};
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
        int changeRoute[timesArray[m][n]];
        int indexX = m;
        int indexY = n;
        int operationNum = timesArray[m][n] - 1;
        while ( indexX != 0 || indexY != 0 ) {
            switch (operationArray[indexX][indexY]) {
                case INSERT:
                    indexY--;
                    changeRoute[operationNum--] = INSERT;
                    break;
                case DELETE:
                    indexX--;
                    changeRoute[operationNum--] = DELETE;
                    break;
                case CHANGE:
                    indexX--;
                    indexY--;
                    changeRoute[operationNum--] = CHANGE;
                    break;
                case NO_OPERATION:
                    indexX--;
                    indexY--;
                    break;
                default:
                    //do nothing
                    break;
            }
        }
        s1 = s1.erase(0, 1);
        s2 = s2.erase(0, 1);
        changeWay.push_back(s1);

        for( auto& tempOperation : changeRoute) {
            switch (tempOperation) {
                case INSERT:
                    changeWay.push_back(s1+=s2[s1.length()]);
                    break;
                case DELETE:
                    s1.pop_back();
                    changeWay.push_back(s1);
                    break;
                case CHANGE:
                    s1.pop_back();
                    s1.push_back(s2[s1.length()]);
                    changeWay.push_back(s1);
                    break;
                default:
                    //do nothing
                    break;
            }
        }
        int result = timesArray[m][n];

        for (int i1 = 0; i1 < m + 1; ++i1) {
            delete[] timesArray[i1];
            delete[] operationArray[i1];
        }
        return result;

    }


};