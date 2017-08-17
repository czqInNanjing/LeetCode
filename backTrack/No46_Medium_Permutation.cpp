//
// Created by Qiang Chen on 8/17/17.
//
//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]
#include <vector>
using namespace std;

class No46_Medium_Permutation {

public:
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempResult;
        permute(result, nums, 0);

        return result;
    }
private:
    static void permute(vector<vector<int>> &result, vector<int>& nums, int begin) {

        if( begin >= nums.size() ) {
            result.push_back(nums);
            return;
        }


        permute(result, nums, begin + 1);
        for( int i = begin + 1 ; i < nums.size() ; ++i ) {
                mySwap(nums, begin, i);
                permute(result, nums, begin + 1);
                mySwap(nums, begin, i);
        }



    }
    static void mySwap(vector<int> &nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }




};