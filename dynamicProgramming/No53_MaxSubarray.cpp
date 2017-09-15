//
// Created by Qiang Chen on 29/07/2017.
//
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//        the contiguous subarray [4,-1,2,1] has the largest sum = 6.
#include "vector"
using namespace std;

/*
 * DP的简化版，只是把内存简化到O(1)而已
 */
class No53_MaxSubArray {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            maxEndingHere = maxEndingHere + nums[i] > nums[i] ? maxEndingHere + nums[i] : nums[i];
            maxSoFar = maxSoFar > maxEndingHere ? maxSoFar : maxEndingHere;
        }
        return maxSoFar;

//        int lastMaxNum = 0;
//        int maxNum = 0;
//        int least = -2147483647;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] > least) {
//                least = nums[i];
//            }
//            if ( nums[i] < 0 ) {
//
//                if (lastMaxNum < maxNum) {
//                    lastMaxNum = maxNum;
//                }
//                if (maxNum + nums[i] < 0) {
//                    maxNum = 0;
//                } else {
//                    maxNum += nums[i];
//                }
//            } else {
//                maxNum += nums[i];
//            }
//        }
//        if (least < 0) {
//            return least;
//        }
//        return max(maxNum, lastMaxNum);
    }
};