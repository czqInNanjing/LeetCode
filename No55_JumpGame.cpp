//
// Created by Qiang Chen on 29/07/2017.
//
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.
#include "vector"
using namespace std;
class No55_JumpGame {
public:
    bool canJump(vector<int>& nums) {

        int canReach[nums.size()];
        canReach[0] = 1;
        for (int j = 1; j < nums.size(); ++j) {
            canReach[j] = 0;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (canReach[i] == 1) {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (i + j < nums.size()) {
                        canReach[i + j] = 1;
                    }

                }
            }
        }

        return canReach[nums.size() - 1] == 1;



    }
};