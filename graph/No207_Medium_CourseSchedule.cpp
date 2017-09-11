//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <unordered_set>
using namespace std;
class No207_Medium_CourseSchedule{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        // way1 bfs
        return bfs(graph);
        // or way2 dfs
//        return dfs(graph);

    }
    bool bfs(vector<unordered_set<int>>& graph) {
        vector<int> indegrees =  computeInDegree(graph);
        return bfs(graph, indegrees);
    }
    bool bfs(vector<unordered_set<int>>& graph, vector<int>& indegrees) {
        vector<bool> deleted(graph.size(), false);
        for (int i = 0; i < graph.size(); ++i) {
            int nextToDelete = -1;
            for (int j = 0; j < graph.size(); ++j) {
                if(!deleted[j] && !indegrees[j]) {
                    deleted[j] = true;
                    nextToDelete = j;
                    break;
                }
            }
            if(nextToDelete == -1)
                return false;
            else {
                for(auto v : graph[nextToDelete])
                    indegrees[v]--;
            }
        }
        return true;
    }
    vector<unordered_set<int>> make_graph(int course, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(course);
        for(auto& edge : prerequisites) {
            graph[edge.second].insert(edge.first);
        }
        return graph;
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

    bool dfs(vector<unordered_set<int>>& graph) {
        vector<bool> visited(graph.size(), false), onPath(graph.size(), false);
        for (int i = 0; i < graph.size(); ++i) {
            if(!visited[i] && !dfs(graph, visited, onPath, i))
                return false;
        }
        return true;
    }
    bool dfs(vector<unordered_set<int>>& graph, vector<bool>& visited, vector<bool>& onPath, int vertex) {
        if(onPath[vertex]) return false; // detect circle
        if(visited[vertex]) return true;


        visited[vertex] = onPath[vertex] = true;
        for( auto des : graph[vertex]) {
            if(!dfs(graph, visited, onPath, des))
                return false;
        }
        onPath[vertex] = false;
        return true;

    }
};
