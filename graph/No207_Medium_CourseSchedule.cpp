//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <unordered_set>
using namespace std;
/*
 * 这道题非常的重要，给出了判定有向图中是否有环的方法，或者找出一个可能的拓扑排序
 * BFS: 不断去除indegree为0的点，直到集合为空，如果不能找到下一个点，那么有环。否则删除的顺序就是一个拓扑排序
 * DFS: 从所有点开始DFS如果在路径中出现了重复的点，那么就是有环。寻找拓扑排序的方法就是进行DFS后将当前节点推入，最后再逆序即可
 */
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
