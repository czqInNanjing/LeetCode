//
// Created by Qiang Chen on 13/09/2017.
//

/* TLE 暴力解法
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() <= 1) return s;

        int left = 1;
        for(int i = s.length() - 1; i > 0; --i) {
            if(isPalindrome(s, 0, i)) {
                left = i + 1;
                break;
            }

        }
        if(left == s.length()) return s; // full palindrome

        string temp = s.substr(left, s.length() - left);
        reverse(temp.begin(), temp.end());
        return temp + s;


    }
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};



 */