//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <unordered_set>
using namespace std;
class No210_Medium_CourseScheduleII{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        return dfs(graph);
    }

    vector<int> dfs(vector<unordered_set<int>>& graph) {
        vector<bool> visited(graph.size(), false), onPath(graph.size(), false);
        vector<int> result;
        for (int i = 0; i < graph.size(); ++i) {
            if(!visited[i] && !dfs(result, graph, visited, onPath, i))
                return vector<int>();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool dfs(vector<int>& result, vector<unordered_set<int>>& graph, vector<bool>& visited, vector<bool>& onPath, int vertex) {
        if(onPath[vertex]) return false; // detect circle
        if(visited[vertex]) return true;


        visited[vertex] = onPath[vertex] = true;
        for( auto des : graph[vertex]) {
            if(!dfs(result, graph, visited, onPath, des))
                return false;
        }
        result.push_back(vertex);
        onPath[vertex] = false;
        return true;

    }




    vector<int> bfs(vector<unordered_set<int>>& graph) {
        vector<int> indegrees =  computeInDegree(graph);
        return bfs(graph, indegrees);
    }
    vector<int> computeInDegree(vector<unordered_set<int>>& graph) {
        vector<int> result(graph.size(), 0);
        for(auto& vertex : graph) {
            for(auto val : vertex) {
                result[val]++;
            }
        }
        return result;
    }
    vector<int> bfs(vector<unordered_set<int>>& graph, vector<int>& indegrees) {
        vector<bool> deleted(graph.size(), false);
        vector<int> result;
        for (int i = 0; i < graph.size(); ++i) {
            int nextToDelete = -1;
            for (int j = 0; j < graph.size(); ++j) {
                if(!deleted[j] && !indegrees[j]) {
                    deleted[j] = true;
                    result.push_back(j);
                    nextToDelete = j;
                    break;
                }
            }
            if(nextToDelete == -1)
                return vector<int>(); // fail, return empty set
            else {
                for(auto v : graph[nextToDelete])
                    indegrees[v]--;
            }
        }
        return result;
    }
};
