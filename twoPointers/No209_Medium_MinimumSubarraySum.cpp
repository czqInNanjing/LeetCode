//
// Created by Qiang Chen on 11/09/2017.
//
#include <vector>
#include <cstdlib>
using namespace std;
class No209_Medium_MinimumSubarraySum{
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;

        int tempMin = INT_MAX;
        int tempSum = 0;
        int lastStart = 0;
        for(int i = 0; i < nums.size(); ++i) {
            tempSum += nums[i];
            if(tempSum >= s) {
                while(tempSum - nums[lastStart] >= s) {tempSum -= nums[lastStart]; lastStart++;}
                tempMin = min(tempMin, i - lastStart + 1);
                tempSum -= nums[lastStart];
                lastStart++;
            } else {
                if(tempSum <= 0) {
                    lastStart = i + 1;
                    tempSum = 0;
                }
            }

        }

        return tempMin == INT_MAX ? 0 : tempMin;

    }
};
