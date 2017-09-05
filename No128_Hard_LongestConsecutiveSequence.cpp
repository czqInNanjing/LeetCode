//
// Created by Qiang Chen on 05/09/2017.
//
#include <unordered_map>
#include <vector>
using namespace std;
class No128_Hard_LongestConsecutiveSequence{


public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int parents[nums.size()];
        int weights[nums.size()];
        for(int i = 0 ; i < nums.size() ; ++i) {weights[i] = 1; parents[i] = i;}

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if(map.count(nums[i])) continue; // duplicate element

            map[nums[i]] = i;
            if(map.count(nums[i] - 1)) connect(parents, weights, i, map[nums[i] - 1] );
            if(map.count(nums[i] + 1)) connect(parents, weights, i, map[nums[i] + 1] );


        }

        int maxW = weights[0];
        for (int j = 1; j < nums.size(); ++j) {
            maxW = max(maxW, weights[j]);
        }
        return maxW;
    }

    void connect(int parents[], int weights[], int a, int b) {
        int rootA = findParent(parents, a);
        int rootB = findParent(parents, b);

        if(rootA == rootB) return;
        if(weights[rootA] >= weights[rootB]) {
            parents[rootB] = rootA;
            weights[rootA] += weights[rootB];
        } else
            connect(parents, weights, rootB, rootA);
    }

    int findParent(int parents[], int i) {
        int parent = i;
        while(parents[parent] != parent) {
            parents[parent] = parents[parents[parent]]; // 路径压缩
            parent = parents[parent];
        }
        return parent;
    }
};
