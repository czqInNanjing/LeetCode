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
    static vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return vector<vector<int>>();

        vector<vector<int>> result;
        vector<int> tempResult;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        permute(result, nums, tempResult, used);

        return result;
    }
private:
    static void permute(vector<vector<int>> &result, vector<int>& nums, vector<int>& tempResult, vector<bool> &used) {

        if(tempResult.size() == nums.size()){
            result.push_back(tempResult);
            return;
        }
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if(used[i]) continue;

            if(i>0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            tempResult.push_back(nums[i]);
            permute(result, nums, tempResult, used);
            used[i] = false;
            tempResult.pop_back();


        }



    }
// 解法2 利用next permutation
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> result;
//        vector<int> tempResult(nums);
//        result.push_back(tempResult);
//        int size = nums.size();
//        while(true) {
//            nextPermutation(tempResult);
//            bool theSame = true;
//            for(int i = 0 ; i < size ; ++i) {
//                if(tempResult[i] != nums[i]) {
//                    theSame = false;
//                    break;
//                }
//            }
//            if(theSame)
//                return result;
//            else
//                result.push_back(tempResult);
//        }
//
//
//
//
//    }
//private:
//    void nextPermutation(vector<int>& nums) {
//        if(nums.size() <= 1)
//            return;
//
//        int index = -1;
//        for(int i = nums.size() - 2 ; i >=0 ; i-- ) {
//            if(nums[i] < nums[i + 1]) {
//                index = i;
//                break;
//            }
//        }
//
//        if(index == -1 ) {
//            reverse(nums.begin(), nums.end());
//            return;
//        }
//        int nextBig = -1;
//        for(int i = nums.size() - 1; i > index; i-- ) {
//            if(nums[i] > nums[index]){
//                nextBig = i;
//                break;
//            }
//        }
//        swap(nums[index], nums[nextBig]);
//        reverse(nums.begin() + index + 1, nums.end());
//    }
//



// 可行解法3，但是私有方法里的nums必须不能使用引用，会破坏循环
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        permute(result, nums, 0);
//
//        return result;
//    }
//private:
//    void permute(vector<vector<int>> &result, vector<int> nums, int begin) {
//
//        if( begin == nums.size() ) {
//            result.push_back(nums);
//            return;
//        }
//
//
//        for( int i = begin ; i < nums.size() ; ++i ) {
//            if(i != begin && nums[begin] == nums[i] ) continue;
//
//            mySwap(nums, begin, i);
//            permute(result, nums, begin + 1);
//
//
//        }
//
//
//
//    }
//    void mySwap(vector<int> &nums, int x, int y) {
//        int temp = nums[x];
//        nums[x] = nums[y];
//        nums[y] = temp;
//    }



};
