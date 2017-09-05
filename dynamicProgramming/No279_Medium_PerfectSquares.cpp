//
// Created by Qiang Chen on 05/09/2017.
//

// 开静态数组可以大幅增加速度
#include <vector>
using namespace std;
class No279_Medium_PerfectSquares{
public:
    int numSquares(int n) {
        vector<int> squares;
        int temp = 1;
        while(temp <= n) {
            squares.push_back(temp*temp);
            temp++;
        }
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1; i < n + 1 ; i++ ) {
            int min = dp[i - 1] + 1;
            for(int j = 1 ; j < squares.size() ; j++ ) {
                if(i - squares[j] >= 0) {
                    if(dp[i - squares[j]] + 1 < min)
                        min = dp[i - squares[j]] + 1;
                } else {
                    break;
                }
            }
            dp[i] = min;
        }
        return dp[n];
    }
};
