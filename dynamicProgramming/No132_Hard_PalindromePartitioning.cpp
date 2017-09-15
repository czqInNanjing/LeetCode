//
// Created by Qiang Chen on 15/09/2017.
//
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    /*
     * 《算法竞赛入门》中提到的，先做预处理获取s[i, j ]是否为回文数，使得状态决策变为O(1)，
     */
    int minCut(string s) {
        if(s.empty()) return 0;

        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));// whether s[j , i] is palindrome (j < i)
        for(int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
            int index = 1;
            while(i - index >= 0 && i + index < n && s[i - index] == s[i + index]) {
                isPalindrome[i - index][i + index] = true;//odd
                index++;
            }
            index = 0;
            while(i - index >= 0 && i + index + 1 < n && s[i - index] == s[i + index + 1]) {
                isPalindrome[i - index][i + index + 1] = true; // even
                index++;
            }
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n ; ++i) {
            for (int j = 1; j <= i; ++j) {
                if(isPalindrome[j - 1][i - 1]) dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        return dp[s.length()] - 1;
    }
};

/*   一开始的解法，暴力枚举i, j  TLE
class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        int result = INT_MAX;
        partition(result, 0, s, 0);
        return result;
    }

    void partition(int& result, int temp, string s, int start) {
        if(start >= s.size()) {result = min(result, temp - 1); return;}

        if(temp >= result) return;
        for(int i = start; i < s.size(); i++ ) {
            if(isPalindrome(s, start, i)) {
                partition(result, temp + 1, s, i + 1);
            }
        }
    }
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};




 */