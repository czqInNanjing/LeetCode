//
// Created by Qiang Chen on 06/09/2017.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class No127_Medium_WordLadder{
public:
    // 可行的解法：双方向广度优先搜索
    int ladderLength2(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> begSet, endSet, *set1, *set2;
        begSet.insert(start);
        endSet.insert(end);
        int h=1, K=start.size();
        while(!begSet.empty()&&!endSet.empty()){
            if(begSet.size()<=endSet.size()){   //Make the size of two sets close for optimization
                set1=&begSet;	//set1 is the forward set
                set2=&endSet;	//set2 provides the target node for set1 to search
            }
            else{
                set1=&endSet;
                set2=&begSet;
            }
            unordered_set<string> itmSet;	//intermediate Set
            h++;
            for(auto i=set1->begin();i!=set1->end();i++){
                string cur=*i;
                for(int k=0;k<K;k++){	//iterate the characters in string cur
                    char temp=cur[k];
                    for(int l=0;l<26;l++){	//try all 26 alphabets
                        cur[k]='a'+l;
                        auto f=set2->find(cur);
                        if(f!=set2->end())return h;
                        f=dict.find(cur);
                        if(f!=dict.end()){
                            itmSet.insert(cur);
                            dict.erase(f);
                        }
                    }
                    cur[k]=temp;
                }
            }
            swap(*set1, itmSet);
        }
        return 0;
    }



    // 换成邻接表之后居然就AC了。。。。。开心，虽然效率比较低   谨慎使用邻接矩阵。。。。。。(下面是邻接矩阵的）
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.empty()) return 0;
        vector<string>::iterator result = find(wordList.begin(), wordList.end(), endWord);
        if(result == wordList.end()) return 0; // endWord not exist in wordList
        if (wordList.back() != endWord ) swap(wordList.back(), *result);

        int n = wordList.size() + 1;
        vector<vector<int>> graph(n, vector<int>());
        vector<string> wordListWithStart(wordList);
        wordListWithStart.insert(wordListWithStart.begin(), beginWord);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected(wordListWithStart[i], wordListWithStart[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        return bfs(graph, 0, n - 1);
    }

    int bfs(vector<vector<int>>& graph, int start, int end) {
        if(start == end) return 0;

        int level = 1;
        unordered_set<int> exist;
        queue<int> nextLevel;
        nextLevel.push(start);
        exist.insert(start);
        while (!nextLevel.empty()) {
            int size = nextLevel.size();
            for (int i = 0; i < size; ++i) {
                int next = nextLevel.front();
                nextLevel.pop();
                if(next == end)
                    return level;
                for (int j = 0; j < graph.size(); ++j) {
                    if(find(graph[next].begin(), graph[next].end(), j) != graph[next].end() && !exist.count(j))
                    {nextLevel.push(j); exist.insert(j);}
                }
            }
            level++;
        }
        return 0;
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

    // 纪念第一次内存越界。。。。。。。。。BFS写的还是不错的，不能黑。。。。自我欣赏一下吧，然后再去学习大神写的代码
    /*
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.empty()) return 0;
        vector<string>::iterator result = find(wordList.begin(), wordList.end(), endWord);
        if(result == wordList.end()) return 0; // endWord not exist in wordList
        if (wordList.back() != endWord ) swap(wordList.back(), *result);

        int n = wordList.size() + 1;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<string> wordListWithStart(wordList);
        wordListWithStart.insert(wordListWithStart.begin(), beginWord);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected(wordListWithStart[i], wordListWithStart[j])) {
                    graph[i][j] = graph[j][i] = 1;
                }
            }
        }

        return graph(graph, 0, n - 1);
    }

    int graph(vector<vector<int>>& graph, int start, int end) {
        if(start == end) return 0;

        int level = 1;
        unordered_set<int> exist;
        queue<int> nextLevel;
        nextLevel.push(start);
        exist.insert(start);
        while (!nextLevel.empty()) {
            int size = nextLevel.size();
            for (int i = 0; i < size; ++i) {
                int next = nextLevel.front();
                nextLevel.pop();
                if(next == end)
                    return level;
                for (int j = 0; j < graph.size(); ++j) {
                    if(graph[next][j] && !exist.count(j)) {nextLevel.push(j); exist.insert(j);}
                }
            }
            level++;
        }
        return 0;
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
     */
};
