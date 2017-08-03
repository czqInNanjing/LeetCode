//
// Created by Qiang Chen on 03/08/2017.
//
/*
 * key: array, in-place, O(n)
 *      not worry about the removed element,
 */
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//        Given input array nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
//

#import "vector"
using namespace std;
class No26_RemoveDuplicateNumberFromSortedArray {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 )
            return 0;

        int lastElement = nums[0];
        int removeNums = 0;
        for( int i = 1 ; i < nums.size() ; i++ ) {
            if ( nums[i] == lastElement ) {
                removeNums++;
            } else {
                nums[i - removeNums] = nums[i];
            }
            lastElement = nums[i];
        }
        return nums.size() - removeNums;



    }
};