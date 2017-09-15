//
// Created by Qiang Chen on 29/07/2017.
//
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//        You can assume that you can always reach the last index.
#include "vector"

using namespace std;

class No45_JumpGame2 {
public:
    /*
     * Solution2 Accepted  runtime 615ms
     */
    int jump(vector<int> &nums) {

        int lastPosition[nums.size()];
        // set the lastPosition that need jump times  to the last position
        lastPosition[0] = nums.size() - 1;

        for (int k = 1; k < nums.size(); ++k) {
            lastPosition[k] = INT32_MAX;
        }
        // 从后往前回溯，看看自己跳一次能超过之前存储的
        for (int i = nums.size() - 2; i >= 0; --i) {

            for (int j = 0; j < nums.size(); ++j) {
                if (nums[i] + i >= lastPosition[j]) {
                    lastPosition[j + 1] = i;
                    break;
                }
            }


        }

        for (int l = 0; l < nums.size(); ++l) {
            if (lastPosition[l] == 0)
                return l;
        }
        return 0;
    }


 /*
  * Time Limit Exceed  pass 91/92 test cases
  */


//    int jump(vector<int> &nums) {
//
//        int reachTime[nums.size()];
//        reachTime[0] = 0;
//        for (int k = 1; k < nums.size(); ++k) {
//            reachTime[k] = INT32_MAX;
//        }
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = 1; j <= nums[i]; ++j) {
//                if (i + j < nums.size()) {
//                    reachTime[i + j] = min(reachTime[i] + 1, reachTime[i + j]);
//                }
//
//            }
//        }
//
//
//        return reachTime[nums.size()];
//    }
};