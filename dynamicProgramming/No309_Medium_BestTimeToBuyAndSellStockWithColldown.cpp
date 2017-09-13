//
// Created by Qiang Chen on 13/09/2017.
//
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
 * 这道题其实难的丧心病狂。。。。。。。
 * https://discuss.leetcode.com/topic/30421/share-my-thinking-process?page=1
 * 反正我看解析看了好久才懂
 * 一个最重要的思路是以什么结尾的序列
 * sell[i] 表示的是 所有以sell结尾的序列，并不一定长度为i， 为任意 比小的数
 * buy[3] = 0 max of [buy], [rest, buy], [rest, rest, buy], [rest, rest, rest, buy], [buy, sell, rest, buy]
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preBuy = INT_MIN;
        int preSell = 0;
        int buy(INT_MIN), sell(0);
        for(int price : prices) {
            preBuy = buy;
            buy = max(preBuy, preSell - price);
            preSell = sell;
            sell = max(preBuy + price, preSell);
        }
        return sell;
    }
};