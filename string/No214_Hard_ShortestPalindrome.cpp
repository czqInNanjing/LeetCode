//
// Created by Qiang Chen on 11/09/2017.
//
#include <string>
using namespace std;
class No214_Hard_ShortestPalindrome{



    /*
     *  TLE 解法   最后一个测试用例太变态了。。。。。。。

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
    */

    /*
     * 原始解法，可以判断从两边增加字符的话，如何最短 。 。。 理解错误，只能从左边加

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
        int right = 1;
        for(int i = 0; i < s.length() - 1; ++i) {
            if(isPalindrome(s, i, s.length() - 1)) {
                right = s.length() - i;
                break;
            }
        }

        if(left < right) {
            string temp = s.substr(0, s.length() - right);
            reverse(temp.begin(), temp.end());
            return s + temp;
        } else {
            string temp = s.substr(left, s.length() - left);
            reverse(temp.begin(), temp.end());
            return temp + s;
        }

    }
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
     */
};
