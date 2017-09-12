//
// Created by Qiang Chen on 11/09/2017.
//

// 我这不算是标准的回溯，请查看  https://discuss.leetcode.com/topic/46159/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partitioning
#include <vector>
using namespace std;
class No78_Medium_Subsets{
public:


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempResult;
        subsets(result, nums, tempResult, 0);
        return result;

    }

    void subsets(vector<vector<int>>& result, vector<int>& nums, vector<int>& tempResult, int start) {
        if(start >= nums.size()) {result.push_back(tempResult); return;}

        tempResult.push_back(nums[start]);
        subsets(result, nums, tempResult, start + 1);
        tempResult.pop_back();
        subsets(result, nums, tempResult, start + 1);
    }
};
