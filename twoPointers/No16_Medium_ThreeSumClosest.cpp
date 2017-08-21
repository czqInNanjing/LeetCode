//
// Created by Qiang Chen on 8/19/17.
//
#include <vector>
#include <cstdlib>
using namespace std;
class No16_Medium_ThreeSumClosest{
    public:
        int threeSumClosest(std::vector<int>& nums, int target) {
            if(nums.size() < 3)
                return 0;

            sort(nums.begin(), nums.end());
            int minDistance = INT_MAX;
            int result = -1;
            for (int i = 0 ; i < nums.size() - 2 ; ++i ) {

                if( i > 0 && nums[i] == nums[i - 1])  // skip the duplicate char
                    continue;

                int j = i + 1;
                int k = nums.size() - 1;

                while( j < k ) {
                    int temp = nums[i] + nums[j] + nums[k];

                    if(abs(temp - target) < minDistance) {
                        result = temp;
                        minDistance = abs(temp - target);
                    }

                    if(temp > target) {
                        k--;
                        while(j < k && nums[k] == nums[k + 1]) k--;
                    }
                    else if(temp < target) {
                        j++;
                        while(j < k && nums[j] == nums[j - 1]) j++;
                    } else
                        return target;


                }
            }
            return result;
        }

};