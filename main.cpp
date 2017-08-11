#include <iostream>
#include <vector>
#include "No54_SprialMatrix.cpp"
#include "No51_NQueens.cpp"
#include "Exer1_DistanceBetweenTwoStrings.cpp"
using namespace std;
int main() {

    Exer1_DistanceBetweenTwoString comparator;
    vector<string> result;
    string s1("sailn");
    string s2("failing");
    cout << comparator.distanceBetweenStrings(s1, s2 , result) << endl;

    for(auto& temp: result) {
        cout << temp << endl;
    }




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