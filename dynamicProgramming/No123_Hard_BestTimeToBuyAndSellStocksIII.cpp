//
// Created by Qiang Chen on 06/09/2017.
//
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class No123_Hard_BestTimeToBuyAndSellStocksIII {
public:
//     f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
    int maxProfit(vector<int>& prices) {
        return 0;
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
    }
};
