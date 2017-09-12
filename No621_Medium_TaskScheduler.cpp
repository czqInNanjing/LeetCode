//
// Created by Qiang Chen on 12/09/2017.
//
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <set>
using namespace std;


/*
 * 这道题还是学到了很多东西的： 集合类不能放指针，否则没办法排序。。。很麻烦
 * 重载运算符还是要学一波的
 */
struct Task {
    char name;
    int val;
    Task(char c, int i): name(c), val(i) {};
    bool operator < (const Task& another) const{
        return val < another.val;
    }

};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;

        for(char temp : tasks) map[temp]++;
        priority_queue<Task> que;
        queue<Task> waitQueue;

        for(unordered_map<char, int>::iterator iter = map.begin(); iter != map.end(); ++iter) {
            que.push(Task(iter->first, iter->second));
        }
        int result = 0;
        Task idle('0', 0);
        int toFinished = que.size();
        while(toFinished) {
            result++;
            if(!waitQueue.empty()) {
                Task& temp = waitQueue.front();waitQueue.pop();
                if(temp.name != idle.name)
                    que.push(temp);
            }

            if(!que.empty()) {
                Task next = que.top();que.pop();
                cout << next.name << ' ';
                next.val -= 1;
                if(next.val) {
                    while(waitQueue.size() < n )
                        waitQueue.push(idle);
                    waitQueue.push(next);
                }
                else toFinished--;
            } else {
                cout << "idle" << " ";
            }
        }
        return result;
    }
};

//int main(){
//    Solution solution;
//    vector<char> task = {'A','A','A','A','A','A','B','C','D','E','F','G'};
//    cout << solution.leastInterval(task, 2);
//}