//
// Created by Qiang Chen on 07/08/2017.
//
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
#include <string>
using namespace std;
class No32_LongestValidParentheses {

public:
    int longestValidParentheses(string s) {
        int lastMax = 0;
        int tempMax = 0;


        int left = 0;
        int right = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
                if (left == right) {
                    tempMax += 2;
                } else if (left < right) { // error
                    lastMax = lastMax > tempMax ? lastMax : tempMax;
                    left = right = tempMax = 0;
                }
            }
        }
        return  lastMax > tempMax ? lastMax : tempMax;
    }



};
