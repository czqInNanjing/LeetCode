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

bool cmp(Interval& i1, Interval& i2) {
    return i1.start < i2.start;
}
class No56_Medium_MergeIntervals {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> result;

        int start = 0;
        while(start < intervals.size()) {
            int minStart = intervals[start].start;
            int maxEnd = intervals[start].end;

            while(++start < intervals.size() && maxEnd >= intervals[start].start) {
                maxEnd = max(maxEnd, intervals[start].end);
            }
            result.push_back(Interval(minStart, maxEnd));
        }

        return result;


    }
};
