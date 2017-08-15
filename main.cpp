#include <iostream>
#include <vector>
#include "No54_SprialMatrix.cpp"
#include "No51_NQueens.cpp"
#include "dynamicProgramming/Exer1_DistanceBetweenTwoStrings.cpp"
#include "dynamicProgramming/Exer2_LongestCommonSubsequence.cpp"
#include "dynamicProgramming/Exer3_LongestIncreasingSubsequence.cpp"
using namespace std;
int main() {

    Exer3_LongestIncreasingSubsequence test;
    int temp[] = {1,1,2,2,3,3,4,4,5, 3 , 7 , 5, 7, 7};
    cout << test.longestIncreasingSubsequence(temp, 14) << endl;

//    Exer2_LongestCommonSubsequence comparator;
//    string s1("ABCBDAB");
//    string s2("BDCABA");
//    vector<string> result = comparator.longestCommonSubsequence(s1, s2);
//
//    for(auto& temp: result) {
//        cout << temp << endl;
//    }


//    Exer1_DistanceBetweenTwoString comparator;
//    vector<string> result;
//    string s1("abcde");
//    string s2("bcd");
//    cout << comparator.distanceBetweenStrings(s1, s2 , result) << endl;
//
//    for(auto& temp: result) {
//        cout << temp << endl;
//    }




    /*
     *
     */
//    No51_NQueens nQueens;
//
//    vector<vector<string>> result = nQueens.solveNQueens(8);
//
//    for (int i = 0; i < result.size(); ++i) {
//        cout << "The " << i + 1 << " result is [ " ;
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << endl;
//        }
//        cout << "] ." << endl;
//    }





//    No54_SprialMatrix* matrix = new No54_SprialMatrix;
//
//    vector<vector<int>> vector1 = {
//            {1 , 2, 3 , 4},
//            { 5, 6 , 7 , 8 },
//            {9 , 10 ,11 ,12}
//    };
//
//    vector<int> result = matrix->spiralOrder(vector1);
//
//    for (int i = 0; i < result.size(); ++i) {
//        cout << result[i] << " " ;
//    }
//
//    std::cout << "Hello, World!" << std::endl;
//
//    return 0;
}