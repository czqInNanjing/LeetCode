//
// Created by Qiang Chen on 8/18/17.
//
//https://leetcode.com/problems/trapping-rain-water/description/
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//        Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


// 这道题我的解法虽然不是很好，但是写的还是比较快的，👍
// 我的解法就是找两端最大的，然后计算中间的大小    右边都比左边小的话，选右边最大的和左边组成一个槽，不然的话选右边刚好比左边大的形成一个槽
#include <vector>
#include <iostream>
using namespace std;
/* 一个比较好的解法：
Here is my idea: instead of calculating area by height*width, we can think it in a cumulative way. In other words, sum water amount of each bin(width=1).
Search from left to right and maintain a max height of left and right separately, which is like a one-side wall of partial container. Fix the higher one and flow water from the lower part. For example, if current height of left is lower, we fill water in the left bin. Until left meets right, we filled the whole container.

class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
 */



class No42_Hard_TrappingRainWater {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int result = 0;
        int n = height.size();
        //  put index that has largest num from this index to the last index
        int maxHeightToLast[height.size()];
        int maxTemp = height.back();
        int maxIndex = n - 1;
        maxHeightToLast[n - 1] = n - 1;
        for(int i = height.size() - 2 ; i >= 0 ; i--) {
            if(height[i] >= maxTemp) {
                maxHeightToLast[i] = i;
                maxTemp = height[i];
                maxIndex = i;
            } else {
                maxHeightToLast[i] = maxIndex;
            }
        }

        int start = 0;
        int leftMax = height[0];
        while( start < n - 1 ) {
            if(height[maxHeightToLast[start + 1]] <= leftMax) {
                result += getDrops(height, start + 1, maxHeightToLast[start + 1]);
                leftMax = height[maxHeightToLast[start + 1]];
                start = maxHeightToLast[start + 1];
            } else {
                for (int i = start + 1; i < n; ++i) {
                    if (height[i] >= leftMax ){
                        result += getDrops(height, start + 1, i);
                        leftMax = height[i];
                        start = i;
                        break;
                    }
                }
            }
        }
        return result;
    }
private:
    int getDrops(vector<int> &height, int left, int right) {
        int leftHeight = height[left - 1];
        int rightHeight = height[right];

        int minHeight = leftHeight < rightHeight ? leftHeight : rightHeight;


        int count = 0;
        for (int i = left; i < right; ++i){
            count += height[i];
        }
        int result = minHeight * (right - left) - count;
        return max(result, 0);
    }
};
