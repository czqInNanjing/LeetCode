//
// Created by Qiang Chen on 8/19/17.
//
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

 */
#include <vector>
#include <cstdlib>
using namespace std;
// 没啥要注意的，就是细心，三个和四个都要做判断跳过重复的字符
// 4调3 3调2 简直无敌。。。。
class No18_Medium_FourSum {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0 ; i < nums.size() - 3; ++i ) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            threeSum(result, nums, i, target - nums[i]);
        }
        return result;
    }
private:
    void threeSum(vector<vector<int>> &result, vector<int>& nums, int start, int target) {

        for( int i = start + 1; i < nums.size() - 2 ; ++i ) {
            if( i > start + 1 && nums[i] == nums[i - 1] ) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while( j < k ) {
                int tempNum = nums[i] + nums[j] + nums[k];
                if(tempNum == target) {
                    vector<int> temp = {nums[start], nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                } else if (tempNum < target) {
                    j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                } else {
                    k--;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }

            }


        }


    }
};