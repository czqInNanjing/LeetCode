//
// Created by Qiang Chen on 06/09/2017.
//
#include <string>
#include <vector>
using namespace std;
class No132_Hard_PalindromePartitioningII{
public:
    // dp[i] = min{dp[i - j] + 1, subStr(j + 1, i) is palindrome}
    int minCut(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.length() + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= s.length() ; ++i) {
            if(isPalindrome(s, 0, i - 1)) {
                dp[i] = 0;
                continue;
            }
            for (int j = 1; j < i; ++j) {
                if (isPalindrome(s, j, i - 1)) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }

            }
        }
        return dp[s.length()];
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }


//    普通回溯剪枝。 TLE
    /*
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
     */
};