//
// Created by Qiang Chen on 08/09/2017.
//
#include "vector"
using namespace std;
class No135_Hard_Candy{
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1)
            return ratings.size();

        int n = ratings.size();

        int pre = 1;
        int total = 1;
        int countDown = 0;
        for(int i = 1; i < n; ++i ) {
            if(ratings[i] >= ratings[i - 1]) {
                if(countDown) {
                    int downNum = (1 + countDown)*countDown/2;
                    total += downNum;
                    if(countDown >= pre) total += countDown - pre + 1;
                    countDown = 0;
                    pre = 1;
                }
                if(ratings[i] > ratings[i - 1])  pre += 1;
                else pre = 1;

                total += pre;
            } else {
                countDown++;
            }


        }
        if(countDown) {
            int downNum = (1 + countDown)*countDown/2;
            total += downNum;
            if(countDown >= pre) total += countDown - pre + 1;
        }
        return total;

    }
};
