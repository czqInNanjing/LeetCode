//
// Created by Qiang Chen on 03/08/2017.
//
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5
#import "vector"
using namespace std;
// key of this problem: median means to split to array into two parts and compute the average of leftMax and rightMin
class No4_MedianOfTwoSortedArray {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if( m > n ) {
            // assure that m <= n
            // we cannot exchange reference directly, if we use nums1 = nums2, it simply copy nums2 = nums1(copy constructor, not assign the address)
            return findMedianSortedArrays(nums2, nums1);
        }

        int iMin = 0;
        int iMax = m;
        int half = (m + n + 1) / 2;
        while (true) {
            int i = (iMin + iMax) / 2;
            int j = half - i;

            if ( i < m && nums2[j - 1] > nums1[i] ) {
                // i is too small, increase i
                iMin++;
            } else if ( i > 0 && nums1[i - 1] > nums2[j] ) {
                // i is too large, decrease i
                iMax--;
            } else {
                int leftMax, rightMin;
                if (i == 0)
                    leftMax = nums2[j - 1];
                else if (j == 0)
                    leftMax = nums1[i - 1];
                else
                    leftMax = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];

                if ( (m + n ) % 2 == 1)
                    return leftMax;

                if ( i == m )
                    rightMin = nums2[j];
                else if (j == n)
                    rightMin = nums1[i];
                else
                    rightMin = nums1[i] < nums2[j] ? nums1[i] : nums2[j];


                return (leftMax + rightMin) / 2.0;
            }






        }

    }
};