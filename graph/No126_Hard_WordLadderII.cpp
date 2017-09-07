//
// Created by Qiang Chen on 06/09/2017.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class No126_Hard_WordLadderII{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;

        if(beginWord.empty()) return result;
        vector<string>::iterator temp = find(wordList.begin(), wordList.end(), endWord);
        if(temp == wordList.end()) return result; // endWord not exist in wordList
        if (wordList.back() != endWord ) swap(wordList.back(), *temp);

        int n = wordList.size() + 1;
        vector<vector<int>> graph(n, vector<int>());
        vector<string> wordListWithStart(wordList);
        wordListWithStart.insert(wordListWithStart.begin(), beginWord);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected(wordListWithStart[i], wordListWithStart[j]) && i != j ) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        bfs(result, graph, 0, n - 1, wordListWithStart);
        return result;


    }


    void bfs(vector<vector<string>>& result, vector<vector<int>>& graph, int start, int end, vector<string>& wordList) {

        int level = 1;
        vector<int> steps(graph.size(), 0);

        // 本题犯的一个巨大的错误，混用steps和visit，试图使用steps为0表示还没有访问过，但是因为steps是在取出来之后才赋值，导致队列里面可能有两个重复的元素，gg
        // BFS要求加进队列里的元素不能再被重复加入。
        // 其实用steps也是可以的，提前赋值即可。。。。。。但是初始值就必须赋值了，感觉吧改bug很容易引入另一个bug。。。
        // 注释掉的是用visit的方法
        queue<int> nextLevel;
        nextLevel.push(start);
//        vector<int> visit(graph.size(), 0);
//        visit[0] = 1;
        steps[0] = 1;
        bool reachEnd = false;
        while (!nextLevel.empty()) {
            int size = nextLevel.size();
            for (int i = 0; i < size; ++i) {
                int next = nextLevel.front();
                nextLevel.pop();
                for (int j = 0; j < graph[next].size(); ++j) {
//                    if(!visit[graph[next][j]]) {
//                        nextLevel.push(graph[next][j]);
//                        visit[graph[next][j]] = 1;
//                    }
                    if(!steps[graph[next][j]]) {
                        steps[graph[next][j]] = level + 1;
                        nextLevel.push(graph[next][j]);
                    }


                }
//                steps[next] = level;
                if(next == end) reachEnd = true;





            }
            if(reachEnd) break;
            level++;


        }

        if(reachEnd) {
            vector<int> currentResult(1, end);
            vector<vector<int>> intResult;
            vector<vector<int>> nextResult;
            intResult.push_back(currentResult);
            while( level != 1  ) {
                for (int i = 0; i < intResult.size(); ++i) {
                    int temp = intResult[i][0];
                    for (int j = 0; j < graph[temp].size(); ++j) {
                        if(steps[graph[temp][j]] == level - 1) {
                            vector<int> newResult(intResult[i]);
                            newResult.insert(newResult.begin(), graph[temp][j]);
                            nextResult.push_back(newResult);
                        }
                    }
                }
                intResult = nextResult;
                nextResult.clear();
                level--;
            }

            for (int k = 0; k < intResult.size(); ++k) {
                vector<string> strResult;
                for (int i = 0; i < intResult[k].size(); ++i) {
                    strResult.push_back(wordList[intResult[k][i]]);
                }
                result.push_back(strResult);
            }
            return;
        }




    }
    bool isConnected(string& s1, string& s2) {
        bool found = false;
        for (int i = 0; i < s1.length(); ++i) {
            if(s1[i] != s2[i]) {
                if (found)
                    return false;
                else
                    found = true;
            }
        }
        // should always not be the same
        return true;
    }
};
