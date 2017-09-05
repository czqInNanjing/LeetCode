//
// Created by Qiang Chen on 02/08/2017.
//
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//        Given nums = [2, 7, 11, 15], target = 9,
//
//        Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
#import "vector"
#import <string>
#import "unordered_map"
using namespace std;
class No1_TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> intMap;

        for (int i = 0 ; i < nums.size(); ++i) {
            if (intMap.find(nums[i]) != intMap.end()) {
                vector<int> result = {intMap[nums[i]], i};
                return result;
            } else {
                intMap[target - nums[i]] = i;
            }
        }
        return vector<int>();

    };
};
