//
// Created by Qiang Chen on 8/17/17.
//
#include <vector>
using namespace std;

//Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//        All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [2, 3, 6, 7] and target 7,
//A solution set is:
//[
//[7],
//[2, 2, 3]
//]


class No39_Medium_CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        vector<int> tempResult;
        putNextNum(result, tempResult, candidates, target, 0);
        return result;
    }

private:
    void putNextNum(vector<vector<int>>& result, vector<int> &tempResult, vector<int>& candidates, int leftNum, int start) {
        if(start >= candidates.size())
            return;

        if(leftNum == 0) {
            result.push_back(tempResult);
            return;
        }
        if(leftNum >= candidates[start]) {
            tempResult.push_back(candidates[start]);
            putNextNum(result, tempResult, candidates, leftNum - candidates[start], start);
            tempResult.pop_back();

        }
        putNextNum(result, tempResult, candidates, leftNum, start + 1);

    }
};



