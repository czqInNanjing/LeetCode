//
// Created by Qiang Chen on 08/09/2017.
//
#include "vector"
using namespace std;
class No134_Medium_GasStation{
public:




    // AC 的低效code
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty() || cost.empty()) return -1;
        int n = gas.size();
        for(int i = 0 ; i < n ; i++ ) {
            int left = 0;
            bool ok = true;
            for( int j = 0; j < n; j++ ) {
                int now = (i + j >= n) ? (i + j - n) : (i + j);
                left += gas[now] - cost[now];
                if(left < 0) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                return i;

        }
        return -1;


    }
};
