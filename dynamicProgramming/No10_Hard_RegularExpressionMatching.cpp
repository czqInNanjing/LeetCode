//
// Created by Qiang Chen on 8/19/17.
//
/*
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
 */
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    }



    // 原来的解法，以为是普通的一个*对应一个或多个 原来是指代前面的位置。。。。。。。气死我了，下面是回溯的思想
//public:
//    bool isMatch(string s, string p) {
//        int sPointer = 0;
//        int pPointer = 0;
//        while( sPointer < s.length() && pPointer < p.length() ) {
//            if(p[pPointer] == '*') {
//                for(int i = sPointer; i < s.length() ; ++i ) {
//                    if(isMatch(s.substr(i), p.substr(pPointer + 1)))
//                        return true;
//                    if(isMatch("", p.substr(pPointer + 1)))  C++ 也可以s<=length() 但是不确定其他语言会不会抛异常什么的，毕竟不存在这个子字符串
//                        return true;
//                }
//                return false;
//            } else if (p[pPointer] == '.') {
//                pPointer++;
//                sPointer++;
//            } else if (s[sPointer] == p[pPointer]) {
//                sPointer++;
//                pPointer++;
//            } else {
//                return false;
//            }
//        }
//
//        if(p.length() == pPointer && s.length() != sPointer )
//            return false;
//
//        if(s.length() == sPointer) {
//            for(int i = pPointer ; i < p.length() ; ++i ) {
//                if (p[i] != '*')
//                    return false;
//            }
//            return true;
//        }
//        return true;
//    }
};