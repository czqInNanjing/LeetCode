//
// Created by Qiang Chen on 8/19/17.
//
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.


 */
#include <vector>
#include <cstdlib>
using namespace std;
// 双指针的题目，没啥好说的，两边到中间，分析清楚即可
class No11_Medium_ContainerWithMostWater {
public:
    int maxArea(vector<int>& height) {

        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int tempArea = min(height[left], height[right])* (right - left );
            if(maxArea < tempArea)
                maxArea = tempArea;
            if(height[left] <= height[right]) {
                int tempLeftMax = height[left];
                left++;
                while(height[left] <= tempLeftMax && left < right) left++;
            } else {
                int tempRightMax = height[right];
                right--;
                while(height[right] <= tempRightMax  && left < right) right--;
            }

        }


        return maxArea;
    }
};
