//
// Created by Qiang Chen on 12/09/2017.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Line {
	int start;
	int end;
	Line(int theStart, int theEnd) : start(theStart), end(theEnd) {}
};

vector<vector<int>>  makeGraph(vector<Line*> lines);
//int main() {
//	int n;
//	cin >> n;
//	vector<Line*> lines;
//	int start, end;
//	Line* line;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> start >> end;
//		line = new Line(start, end);
//		lines.push_back(line);
//	}
//
//	vector<vector<int>> graph = makeGraph(lines);
//
//	int result = 0;
//	for (size_t i = 0; i < n; i++)
//	{
//		vector<bool> ableToUse(n, true);
//		int edgeToUse = i;
//		int tempResult = 0;
//		bool found = true;
//		while (tempResult != n && found) {
//			tempResult++;
//			found = false;
//			ableToUse[edgeToUse] = false;
//			for (size_t j = 0; j < graph[edgeToUse].size(); ++j)
//			{
//				ableToUse[graph[edgeToUse][j]] = false;
//			}
//			for (size_t j = 0; j < n; j++)
//			{
//				if (ableToUse[j]) {
//					found = true;
//					edgeToUse = j;
//				}
//
//			}
//		}
//		result = max(result, tempResult);
//	}
//	cout << n - result;
//	return n - result;
//
//}

vector<vector<int>> makeGraph(vector<Line*> lines) {
	vector<vector<int>> result(lines.size(), vector<int>());
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = i + 1; j < lines.size(); ++j) {
			if (lines[i]->start < lines[j]->start && lines[i]->end > lines[j]->end || lines[i]->start > lines[j]->start && lines[i]->start < lines[j]->end) {
				result[i].push_back(j);
				result[j].push_back(i);
			}
		}
	}
	return result;
}
