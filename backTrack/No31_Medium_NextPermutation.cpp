//
// Created by Qiang Chen on 8/18/17.
//
//https://leetcode.com/problems/next-permutation/description/
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1
//
// 不能算回溯的题目，但是可以用在解回溯的题目 No46,47 从开始一个一个寻找下一个permutation直到回到最开始就可以了，时间效率也还可以吧
//
#include <vector>
#include <sstream>
using namespace std;
class No31_Medium_NextPermutation{
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;

        int index = -1;
        for(int i = nums.size() - 2 ; i >=0 ; i-- ) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        if(index == -1 ) { // 刚好是降序排列
            reverse(nums.begin(), nums.end());
            return;
        }
        int nextBig = -1;
        for(int i = nums.size() - 1; i > index; i-- ) {
            if(nums[i] > nums[index]){
                nextBig = i;
                break;
            }
        }
        swap(nums[index], nums[nextBig]);
        reverse(nums.begin() + index + 1, nums.end());
    }
};
