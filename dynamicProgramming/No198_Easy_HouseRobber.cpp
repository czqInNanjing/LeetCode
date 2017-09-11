//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <string>
#include <set>
using namespace std;
class No198_Easy_HouseRobber{
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;

        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()];
    }
};
