//
// Created by Qiang Chen on 13/09/2017.
//
#include <vector>
using namespace std;
class No416_Medium_PartitionSubset{
public:

    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int whole = 0;
        for(auto temp : nums) whole += temp;
        if(whole % 2 != 0) return false;

        int obj = whole / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(obj + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1];
            for(int j = 0; j < obj; ++j)  {
                if(dp[i - 1][j] && j + nums[i - 1] <= obj) dp[i][j + nums[i - 1]] = true;
            }
            if(dp[i][obj]) return true;
        }


        return dp[nums.size()][obj];
    }

    // TLE
//    bool canPartition(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int whole = 0;
//        for(auto temp : nums) whole += temp;
//        if(whole % 2 != 0) return false;
//
//        int obj = whole / 2;
//        return addToObj(nums, 0, obj);
//    }
//    bool addToObj(vector<int>& nums, int start, int obj) {
//        if(start > nums.size() - 1) return false; // you cannot reach the end
//        if(nums[start] == obj) return true;
//
//        if(addToObj(nums, start + 1, obj - nums[start])
//          || addToObj(nums, start + 1, obj)
//          ) return true;
//
//        return false;
//
//    }
};
