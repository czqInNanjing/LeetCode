//
// Created by Qiang Chen on 8/17/17.
//
//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1,1,2] have the following unique permutations:
//[
//[1,1,2],
//[1,2,1],
//[2,1,1]
//]
#include <vector>
#include <set>
using namespace std;

class No47_Medium_Permutation2 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempResult;
        permute(result, nums, 0);

        return result;
    }
private:
    void permute(vector<vector<int>> &result, vector<int>& nums, int begin) {

        if( begin >= nums.size() ) {
            result.push_back(nums);
            return;
        }


        permute(result, nums, begin + 1);
        for( int i = begin + 1 ; i < nums.size() ; ++i ) {
            set<int> existNums;
            if(nums[begin] != nums[i] ) {
                if(existNums.find(nums[i]) == existNums.end()) {
                    mySwap(nums, begin, i);
                    permute(result, nums, begin + 1);
                    mySwap(nums, begin, i);
                    existNums.insert(nums[i]);
                }

            }

        }



    }
    void mySwap(vector<int> &nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }


};
