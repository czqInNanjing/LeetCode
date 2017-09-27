//
// Created by Qiang Chen on 14/09/2017.
//
#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
/*
 * 利用了84题的结论，使得计算变得容易，从上到下去迭代，轮流计算每一行的矩形最大面积
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<int> h(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') h[j]++; else h[j] = 0;
            }
            result = max(result, getMaxArea(h));
        }
        return result;
    }


    int getMaxArea(vector<int>& val) {

        if (val.empty()) return 0;
        stack<int> sta;
        int currentMax = 0;
        int i = 0;
        for (; i < val.size();) {
            if (sta.empty() || val[sta.top()] <= val[i])
                sta.push(i++);
            else {
                int minToCal = sta.top();
                sta.pop();
                int tempMax = val[minToCal] * (sta.empty() ? i : i - sta.top() - 1);
                currentMax = max(currentMax, tempMax);
            }
        }
        while (!sta.empty())
        {
            int minToCal = sta.top();
            sta.pop();
            int tempMax = val[minToCal] * (sta.empty() ? i : i - sta.top() - 1);
            currentMax = max(currentMax, tempMax);
        }
        return currentMax;
}

};
