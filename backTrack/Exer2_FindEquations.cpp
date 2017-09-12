//
// Created by Qiang Chen on 12/09/2017.
//
#include <iostream>
#include <vector>
using namespace std;
int compute(vector<int>& nums, int target, vector<char>& tempResult, int tempVal, int start);
//int main() {
//    int n, target;
//    cin >> n >> target;
//
//    if(n <= 0) return 0;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    vector<char> tempResult;
//
//    int val = compute(nums, target, tempResult, nums[0], 1);
//    if(val != target) cout << val;
//    return 0;
//}

int compute(vector<int>& nums, int target, vector<char>& tempResult, int tempVal, int start) {
    if(start >= nums.size()) {

        if(target == tempVal) {
            cout << nums[0];
            for (int i = 0; i < nums.size() - 1; ++i) {
                cout << tempResult[i] << nums[i + 1];
            }
        }
        return tempVal;
    }

    tempResult.push_back('+');
    int addResult = compute(nums, target, tempResult, tempVal + nums[start], start + 1);
    if(addResult == target) return target;
    tempResult.pop_back();
    tempResult.push_back('*');
    int multiResult = compute(nums, target, tempResult, tempVal*nums[start], start + 1);
    if(multiResult == target) return target;


    return max(addResult, multiResult);
}