//
// Created by Qiang Chen on 13/08/2017.
//

#include <vector>
#include <iostream>
#include <string>


//　在构造lis[k+1]的时候可以发现，对于s[k+1]，真正有用的元素s[i]<s[k+1]且lis[i]最大。如果记录了不同长度的lis的末尾元素，那么对于新加入的元素s[k+1]，找出前面比它小的且对应lis最长的，就是以s[k+1]为结尾的lis[k+1]的长度。
//
//　　可以发现使用数组MaxV[1...MAXLENGTH]其中MaxV[i]表示长度为i的lis的最小末尾元素，完全可以在s[k+1]时进行lis[k+1]的更新。进一步地发现，其实lis[]数组已经没有用了，对于MaxV[1...MAXLENGTH]中值合法对应的最大下标，就是当前最长的lis，也即利用MaxV[]更新自身。
//
//　　同时，根据MaxV[]的更新过程，可以得出当i<j时，MaxV[i]<MaxV[j]（假设出现了i>j且Max[i]=>Max[j]的情况，那么在之前的处理中，在发现j长度的lis时，应用它的第i个元素来更新Max[i]，仍会导致MaxV[i]<MaxV[j]，这与这个现状发生了矛盾，也即这个情况是不可能到达的）。这样，在寻找小于s[k+1]的值时，可以使用二分查找，从而把时间复杂度降低至O(nlogn)。

using namespace std;

class Exer3_LongestIncreasingSubsequence {

public:
    static int longestIncreasingSubsequence(int* array, int length) {

        if (length <= 0 )
            return 0;

        int minEleWithMaxLen[length];
        minEleWithMaxLen[0] = array[0];
        int result = 1;
        for (int i = 1; i < length; ++i) {

            int tempMaxLen = binarySearch(minEleWithMaxLen, result - 1, array[i]);

            if(tempMaxLen != -2) {
                // 相等的元素被无视，然后查找该元素大于的第一个元素，然后替换掉它的下一个位置（如果没有，替换掉0号位置）
                minEleWithMaxLen[tempMaxLen] = array[i];
                if(tempMaxLen == result) {
                    result++;
                }
            }
            for (int j = 0; j < result; ++j) {
                cout << minEleWithMaxLen[j] << " ";
            }
            cout << endl;
        }
        return result;
    }

private:
    static int binarySearch(int* array, int end, int valueToFind) {
        int result = 0;

        int start = 0;
        while(start <= end) {
            int mid = (start + end) / 2;

            if (valueToFind == array[mid]) {
                return -1;
            } else if( valueToFind > array[mid]) {
                result = mid + 1;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }



        return result;
    }


};