//
// Created by Qiang Chen on 08/09/2017.
//
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
// 这道题就一个注意点，记得考虑多种边界情况就好，考试的时候不一定能让你试错。。。。。。
class No57_Hard_InsertIntervals{
   vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;


        bool found = false;
        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else {
                found = true;
                if(intervals[i].start > newInterval.end) {
                    result.push_back(newInterval);
                } else {
                    int start = min(intervals[i].start, newInterval.start);
                    int end = max(intervals[i].end, newInterval.end);
                    while(++i < intervals.size() && intervals[i].start <= end) {
                        end = max(intervals[i].end, end);
                    }
                    result.push_back(Interval(start, end));
                }


                while(i < intervals.size()) {  // add the following element
                    result.push_back(intervals[i]);
                    i++;
                }
            }


        }
        if(!found) result.push_back(newInterval);
        return result;
    }
};
