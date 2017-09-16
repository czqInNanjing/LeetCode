//
// Created by Qiang Chen on 15/09/2017.
//

#include <iostream>
#include <vector>
using namespace std;

bool backtrack(vector<int>& nums, int start, double curr, double des, double last);
//int main() {
//
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    int result;
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    cin >> result;
//
//    return backtrack(nums, 0, 0, result, 0) ? 1 : 0;
//
//
//}


bool backtrack(vector<int>& nums, int start, double curr, double des, double last) {
    if(start >= nums.size()) {
        return curr - last < 0.000000001;
    }

    return backtrack(nums, start + 1, curr + nums[start], des, nums[start])
           || backtrack(nums, start + 1, curr - nums[start], des, -nums[start])
            || backtrack(nums, start + 1, curr - last + last*nums[start], des, last*nums[start])
           || backtrack(nums, start + 1, curr - last + last/nums[start], des, last/nums[start]);




}