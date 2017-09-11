//
// Created by Qiang Chen on 09/09/2017.
//
#include <vector>
#include <set>
using namespace std;
class No77_Medium_Combination{
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        combine(result, temp, 1, n, k);
        return result;
    }
    void combine(vector<vector<int>>& result, vector<int>& temp, int start, int n, int left) {
        if(left == 0) {result.push_back(temp); return;}
        if(n - start < left - 1) return;

        for(int i = start; i <= n - left + 1; ++i ) {
            temp.push_back(i);
            combine(result, temp, i + 1, n, left - 1);
            temp.pop_back();
        }


    }
};
