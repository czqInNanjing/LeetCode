//
// Created by Qiang Chen on 13/09/2017.
//
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        combinationSum4(nums, target, dp);
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target, vector<int>& dp) {
        if(dp[target] != -1) return dp[target];
        
        int res = 0;
        for(auto temp : nums)
            if(target - temp >= 0 ) res += combinationSum4(nums, target - temp, dp);
        
        dp[target] = res;
        return res;
    }
};
