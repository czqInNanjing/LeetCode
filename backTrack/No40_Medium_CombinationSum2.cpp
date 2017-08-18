//
// Created by Qiang Chen on 8/17/17.
//
#include <vector>
using namespace std;
//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//        All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
//A solution set is:
//[
//[1, 7],
//[1, 2, 5],
//[2, 6],
//[1, 1, 6]
//]
class No40_Medium_CombinationSum2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return vector<vector<int>>();

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> tempResult;
        vector<bool> used(candidates.size(), false);
        putNextNum(result, tempResult, target, 0, candidates, used);
        return result;
    }
private:
    void putNextNum(vector<vector<int>> &result, vector<int> &tempResult, int leftNum, int start, vector<int> &candidates, vector<bool> &used) {
        if(leftNum < 0 ) {
            return;
        }

        if(leftNum == 0) {
            result.push_back(tempResult);
            return;
        }

        for (int i = start; i < candidates.size(); ++i){
            if( i > 0 && candidates[i - 1] == candidates[i] && !used[i - 1]) continue;

            used[i] = true;
            tempResult.push_back(candidates[i]);
            putNextNum(result, tempResult, leftNum - candidates[i], i + 1, candidates, used);
            tempResult.pop_back();
            used[i] = false;
        }




    }
};