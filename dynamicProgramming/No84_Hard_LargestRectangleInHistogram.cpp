//
// Created by Qiang Chen on 14/09/2017.
//

#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
int getMaxArea(vector<int> val) {
    /*
     * 计算方式：对于每个矩形，计算向两边拓展的最大距离，故最大宽度不能小于该矩形的高，right 很简单，遇到比你矮的就开始计算，左边始终存储比你低的第一个数
     */
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




//int main() {
//	vector<int> input = { 6, 2, 5, 4, 5, 1, 6 };
//	cout << getMaxArea(input);
//}