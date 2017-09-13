//
// Created by Qiang Chen on 13/09/2017.
//
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int priceSize = prices.size();
        K = min(priceSize - 1, K);

        if(K > priceSize / 2) {  //  和III的区别， 就是避免TLE，当次数较多的时候，超过一半的时候，每一次有机会买入即可（因为上升的阶段数量不会超过n / 2, 所以可以随便买）
            int maxPro = 0;
                for (int i = 1; i < priceSize; i++) {
                    if (prices[i] > prices[i-1])
                        maxPro += prices[i] - prices[i-1];
                }
                return maxPro;
        }

        if (prices.size() <= 1) return 0;
        else {
            int maxProf = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
    }
};