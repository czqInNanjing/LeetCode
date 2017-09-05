//
// Created by Qiang Chen on 04/09/2017.
//
#include <vector>
#include <numeric>
#include <functional>

using namespace std;
class No260_Medium_SingleNumberIII {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff; // 取出最后一位为1的数
        vector<int> result = {0, 0};
        for (int i = 0; i < nums.size(); ++i) { // 把所有的数分成两组
            if(nums[i] & diff)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];


        }
        return result;
    }
};