//
// Created by Qiang Chen on 8/19/17.
//
//https://leetcode.com/problems/longest-palindromic-substring/discuss/

//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//        Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//Example:
//
//        Input: "cbbd"
//
//Output: "bb"



#include "string"
using namespace std;
// 这道题神奇在它的解法居然可以很简单，只需要从每个字符出发，尝试去扩展这个字符为中心的回文数就可以了
// 还可以做一些优化，例如如果起始字符距离两端最小距离不如当前最大距离的一半直接跳过，或者直接跳过重复的字符（即以重复的字符作为中心），但是影响不大，简单最好
class No5_Medium_LongestPalindromicString {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2) {
            return s;
        }

        for (int i = 0; i < s.length(); ++i)
        {
            extend(s, i, i);
            // 这里可以判断 s[i] == s[i + 1]的话再执行
            // 甚至可以不停地向右扩展看看是否一直重复，然后就可以跳过以这些字符为中心的回文串，大大加快速度，参考下面的解法
            extend(s, i, i + 1);
        }
        return s.substr(maxLow, maxLen);

    }
private:
    int maxLow, maxLen;
    void extend(string &s, int low, int high) {

        while(low >= 0 && high < s.length() && s[low] == s[high]) {
            low--;
            high++;
        }
        low++;
        high--;


        if(high - low + 1 > maxLen) {
            maxLen = high - low + 1;
            maxLow = low;
        }


    }
};

//一个优化的解法
//string longestPalindrome(string s) {
//    if (s.empty()) return "";
//    if (s.size() == 1) return s;
//    int min_start = 0, max_len = 1;
//    for (int i = 0; i < s.size();) {
//        if (s.size() - i <= max_len / 2) break;
//        int j = i, k = i;
//        while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
//        i = k+1;
//        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
//        int new_len = k - j + 1;
//        if (new_len > max_len) { min_start = j; max_len = new_len; }
//    }
//    return s.substr(min_start, max_len);
//}

