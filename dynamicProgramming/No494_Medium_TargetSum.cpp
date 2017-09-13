//
// Created by Qiang Chen on 13/09/2017.
//
#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i : nums) sum += i;

        if( (target + sum) % 2 != 0 ) return 0;
        if(sum < target) return 0;
        int obj = (target + sum) / 2;

        // 这道题当obj过大的时候有可能内存不足， 最好还是降维吧
        // 降维的话j从高到低，因为只会用到更低的，所以从高到低保证所有未用到的数据都是上一次的
        vector<vector<int>> dp(nums.size() + 1, vector<int>(obj + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1];
            for(int j = 0; j <= obj; j++) {
                if(j + nums[i - 1] <= obj) dp[i][j + nums[i - 1]] += dp[i - 1][j];
            }

        }

        return dp[nums.size()][obj];

    }
};