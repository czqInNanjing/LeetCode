//
// Created by Qiang Chen on 13/09/2017.
//
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:




    // TLE 没看清题意，未利用本来就是树这一事实
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph = makeGraph(n, edges);
        vector<int> result;
        int currentMin = INT_MAX;
        for(int i = 0; i < n; ++i) {
            bfs(graph, i, result, currentMin);
            if(currentMin == INT_MAX) return result; // not a connective graph
        }
        return result;
    }
    void bfs(vector<vector<int>>& graph, int start, vector<int>& result, int& currentMin) {

        int level = 0;
        int count = 1;// count of node visited
        queue<int> que;
        vector<bool> visited(graph.size(), false);
        que.push(start);
        visited[start] = true;
        while(!que.empty()) {
            level++;
            if(level > currentMin) return;

            int size = que.size();
            for(int i = 0; i < size; ++i) {
                int next = que.front();que.pop();
                for(auto des : graph[next]) {
                    if(!visited[des]) {
                        que.push(des);
                        visited[des] = true;
                        count++;
                    }
                }
            }
            if(count == graph.size()) {
                if(level == currentMin) result.push_back(start);
                else if(level < currentMin) {result.clear(); result.push_back(start); currentMin = level;}
            }
        }
    }
    vector<vector<int>> makeGraph(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto& edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        return graph;
    }


};