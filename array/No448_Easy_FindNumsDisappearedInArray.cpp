//
// Created by Qiang Chen on 12/09/2017.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1)
                result.push_back(i + 1);
        }
        return result;
    }
};