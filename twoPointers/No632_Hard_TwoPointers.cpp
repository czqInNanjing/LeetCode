//
// Created by Qiang Chen on 12/09/2017.
//
#include<vector>
#include <map>
#include <unordered_set>
#include <iostream>
// 窗口思维的一个注意点： 满足情况的时候移动左端口一直找到最小长度的为止，而不是立即移动右指针
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, vector<int>> numListMap;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                numListMap[nums[i][j]].push_back(i);
            }
        }
        int start = INT_MIN / 3, end = INT_MAX / 3;  // 防止越界
        int count = 0;
        auto left = numListMap.begin();
        auto right = numListMap.begin();
        map<int, int> existMap;
        unordered_set<int> exist;
        while(right != numListMap.end()) {
            for(int x : right->second) {
                existMap[x]++;
            }

            exist.insert(right->second.begin(), right->second.end());
            if(exist.size() == nums.size()) {

                while(true) {
                    if(right->first - left->first < end - start) {
                        start = left->first;
                        end = right->first;
                    }
                    bool noEnough = false;
                    for(int temp : left->second) {
                        if(existMap[temp] > 0) {
                            existMap[temp]--;
                            if(existMap[temp] == 0) {
                                exist.erase(temp);
                                noEnough = true;
                            }
                        }

                    }
                    left++;
                    if(noEnough) break;
                }
            }

            right++;
        }


        vector<int> result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};

//int main() {
//    vector<int> temp1 = {4,10,15,24,26};
//    vector<int> temp2 = {0,9,12,20};
//    vector<int> temp3 = {5,18,22,30};
//    vector<vector<int>> temp;
//    temp.push_back(temp1);temp.push_back(temp2);temp.push_back(temp3);
//    Solution solution;
//    vector<int> result = solution.smallestRange(temp);
//    cout << result[0] << result[1];
//
//}