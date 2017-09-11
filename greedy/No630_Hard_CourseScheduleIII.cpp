//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <queue>

using namespace std;
bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1] ;
}

class No630_Hard_CourseScheduleIII {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.empty()) return 0;

        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> que;

        int tempDay = 0;
        for(int i = 0; i < courses.size(); ++i) {
            if(tempDay + courses[i][0] <= courses[i][1]) { // we have enough time
                que.push(courses[i][0]);
                tempDay += courses[i][0];
            } else {
                que.push(courses[i][0]);
                tempDay += courses[i][0];
                tempDay -= que.top();
                que.pop();
            }
        }
        return que.size();
    }
};
