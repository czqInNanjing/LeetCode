//
// Created by Qiang Chen on 05/09/2017.
//

#include <string>
#include <vector>
using namespace std;
class No283_Easy_MoveZeroes {
public:
    // 巧妙地移动之后后面的直接设置为0，免去了交换
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i])
                nums[j++] = nums[i];
        }
        for (; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }



//    void moveZeroes(vector<int>& nums) {
//        for(int i = 0 ; i < nums.size();) {
//            if(nums[i]) i++;
//            else {
//                bool found = false;
//                for(int j = i + 1 ; j < nums.size() ; j++) {
//                    if(nums[j]) {swap(nums[i], nums[j]); found = true; break;};
//                }
//                if(!found) return;
//            }
//        }
//    }


};
