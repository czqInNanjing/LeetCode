#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "No54_SprialMatrix.cpp"
#include <queue>
#include <set>
#include "backTrack/No51_Hard_NQueens.cpp"
#include "dynamicProgramming/Exer1_DistanceBetweenTwoStrings.cpp"
#include "dynamicProgramming/Exer2_LongestCommonSubsequence.cpp"
#include "dynamicProgramming/Exer3_LongestIncreasingSubsequence.cpp"
#include "backTrack/No47_Medium_Permutation2.cpp"
#include "No42_Hard_TrappingRainWater.cpp"
#include "No264_Medium_UglyNumber2.cpp"
#include "No313_Medium_SuperUglyNumber.cpp"
#include "dynamicProgramming/No115_Hard_DistinctSequences.cpp"
#include "dynamicProgramming/No120_Medium_Triangle.cpp"
#include "dynamicProgramming/No123_Hard_BestTimeToBuyAndSellStocksIII.cpp"
#include "graph/No127_Medium_WordLadder.cpp"
#include "graph/No126_Hard_WordLadderII.cpp"
#include "graph/No130_Medium_SurroundedRegions.cpp"
#include "No132_Hard_PalindromePartitioningII.cpp"
#include "No282_Hard_ExpressionAddOperators.cpp"
using namespace std;
int main() {

    No132_Hard_PalindromePartitioningII test;
    cout << test.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;
    cout << test.minCut("ababa");
//    test.minimumTotal()


//    map<int, vector<int>> map1;
////    cout << map1[0].size();
//    vector<string> tempVec;
//    queue<int> queue1;
//    set<int> set1;
//
//    No282_Hard_ExpressionAddOperators test;
//    tempVec = test.addOperators("123",6 );
//    for (int i = 0; i < tempVec.size(); ++i) {
//        cout << tempVec[i] << endl;
//    }


//    No42_Hard_TrappingRainWater test;
//    vector<int> temp =  {4,2,0,3,2,5};
//    cout << test.trap(temp);


//    vector<int> temp = {1,1,4,4};
//    No47_Medium_Permutation2 permutation;
//    permutation.permuteUnique(temp);

//    Exer3_LongestIncreasingSubsequence test;
//    int temp[] = {1,1,2,2,3,3,4,4,5, 3 , 7 , 5, 7, 7};
//    cout << test.longestIncreasingSubsequence(temp, 14) << endl;

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
//    No51_Hard_NQueens nQueens;
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