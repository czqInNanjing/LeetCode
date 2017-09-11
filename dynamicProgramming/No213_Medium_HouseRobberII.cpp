//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <string>
#include <set>
using namespace std;
class No213_Medium_HouseRobberII{
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        return max(robALine(nums, 0, nums.size() - 2), robALine(nums, 1, nums.size() - 1) );

    }

    int robALine(vector<int>& nums, int start, int end) {
        int include = 0, exclude = 0;
        for( int i = start; i <= end; ++i) {
            int in = include, ex = exclude;
            exclude = max(ex, in);
            include = ex + nums[i];
        }
        return max(exclude, include);
    }
};
