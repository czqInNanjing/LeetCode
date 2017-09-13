//
// Created by Qiang Chen on 06/09/2017.
//
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class No123_Hard_BestTimeToBuyAndSellStocksIII {
public:
    /*
     * 来尝试一下解释这道题吧：
     * 1. dp[K][n] 表示进行第K次交易后在第n天的最大利润
     * 2. dp[K][n] = max(dp[K][n - 1], dp[K - 1][n - j] + prices[n] - prices[j])  1 <= j <= n  定义为进行K次交易在第n天的最大利润为 进行K - 1 次交易后某天买入现在卖出（第n天卖出，则前面某天买入） 或者 K 次交易 n - 1天的利润
     *    或者 dp[K][n] = max(dp[K][n - 1], dp[K - 1][j] + prices[n] - prices[j])  j = [0, n - 1]
     * 3. 如果正常计算dp的话 为o(n^3) 因为每个状态需要n次确定，但是j从低到高计算的值可以累计，变为O(n^2)，于是有了下面的代码
     * 4. 这道题之所以K放在n前面是有原因，状态转移方程最好是前一次的状态进行转移，因此K放在前面更加好定义
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        else {
            int K = 2; // number of max transaction allowed
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
//public:
//     f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
//    int maxProfit(vector<int>& prices) {
//        return 0;
//        if(prices.size() <= 1) return 0;
//        int n = prices.size();
//        int MAX_TIME = 2;
//        vector<vector<int>> dp(MAX_TIME + 1, vector<int>(n + 1, 0));
//        dp[0][0] = 0;
//        int maxProfit = 0;
//        for (int i = 1; i <= MAX_TIME ; ++i) {
//            int tempMax =
//
//
//            for (int j = 1; j <= n; ++j) {
//
//            }
//
//
//
//        }





//        if(prices.size() <= 1) return 0;
//        int n = prices.size();
//        int MAX_TIME = 2;
//        vector<unordered_map<int, int>> minDp(n + 1, unordered_map<int, int>());
//        vector<unordered_map<int, int>> profitDp(n + 1, unordered_map<int, int>());
//
////        profitDp[1] = profitDp[0];
//        unordered_map<int, int> initMap;
//        for (int k = 1; k <= MAX_TIME; ++k) initMap[k] = INT_MAX;
//        initMap[0] = prices[0];
//        minDp[1] = initMap;
//
//        for (int i = 2; i <= n; ++i) {
//            profitDp[i] = profitDp[i - 1];
//            minDp[i] = minDp[i - 1];
//            minDp[i][0] = min(minDp[i - 1][0], prices[i - 1]);
//            for (int j = 1; j <= MAX_TIME ; ++j) {
//
//                if(prices[i - 1] > minDp[i - 1][j - 1]) {
//                    int temp = prices[i - 1] - minDp[i - 1][j - 1] + profitDp[i - 1][j - 1];
//                    if(profitDp[i][j] < temp) {  // 增加一次交易后比原来同样次数交易额多
//                        profitDp[i][j] = temp;
//                        minDp[i][j] = prices[i - 1];
//                        continue;
//                    } else if(profitDp[i][j] == temp) {
//                        minDp[i][j] = min(minDp[i - 1][j], prices[i - 1]);
//                        continue;
//                    }
//                }
//                if(minDp[i - 1][j] != INT_MAX) minDp[i][j] = min(minDp[i - 1][j], prices[i - 1]);
//                cout << "mindp i " << i << " j " << j << " " <<  minDp[i][j] << endl;
//                cout << "profit i " << i << " j " << j <<" " <<  profitDp[i][j] << endl;
//            }
//            cout << endl ;
//        }
//
//        int result = 0;
//        for (int j = 0; j <= MAX_TIME; ++j) {
//            result = max(result, profitDp[n][j]);
//        }
//        return result;
//    }
};
