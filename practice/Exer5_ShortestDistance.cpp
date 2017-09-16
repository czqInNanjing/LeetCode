//
// Created by Qiang Chen on 15/09/2017.
//

//从控制台输入n+1行，前n行每行3个整数，形如“A B d”，表示从节点A到节点B距离为d（双向）。第n+1行形如“A B”，表示求A到B的最短距离。输出此最短距离。
//例如：
//1 42 3
//42 789 4
//1 789 9
//1 789
//输出7
#include<iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int computeBFS(unordered_map<int, vector<int>> graph, unordered_map<int, vector<int>> weight, int start, int end);


//int main() {
//
//    int n;
//    cin >> n;
//    unordered_map<int, int> nameMap;   // name - > id
//    unordered_map<int, vector<int>> graph;
//    unordered_map<int, vector<int>> weight;
//    int x, y, dis;
//    int vertexIndex = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> x >> y >> dis;
//        if(nameMap.count(x)) x = nameMap[x];
//        else x = nameMap[x] = vertexIndex++;
//        if(nameMap.count(y)) y = nameMap[y];
//        else y = nameMap[y] = vertexIndex++;
//
//        graph[x].push_back(y);
//        weight[x].push_back(dis);
//        graph[y].push_back(x);
//        weight[y].push_back(dis);
//    }
//    int start, end;
//    cin >> start >> end;
//    start = nameMap[start];
//    end = nameMap[end];
//    int result = computeBFS(graph, weight, start, end);
//    if(result == INT_MAX) return -1;
//    return result;
//}

int computeBFS(unordered_map<int, vector<int>> graph, unordered_map<int, vector<int>> weight, int start, int end) {




    // Disjska
//    vector<int> disFromStart(graph.size(), INT_MAX);
//    vector<bool> visited(graph.size(), false);
//    disFromStart[start] = 0;
//
//    visited[start] = true;
//    queue<int> que;
//    que.push(start);
//
//    while(!que.empty()) {
//        int next = que.front(); que.pop();
//
//        for (int i = 0; i < graph[next].size(); ++i) {
//            int& des = graph[next][i];
//
//            disFromStart[des] = min(disFromStart[des], disFromStart[next] + weight[next][i]);
//            if(!visited[des]) {
//                que.push(des);
//                visited[des] = true;
//            }
//        }
//    }
//
//    return disFromStart[end];




}