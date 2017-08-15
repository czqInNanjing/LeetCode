//
// Created by Qiang Chen on 07/08/2017.
//
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


//If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.
//
//Else if s[i] is ')'
//
//If s[i-1] is '(', longest[i] = longest[i-2] + 2
//
//Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
#include <string>
#include <vector>
using namespace std;
/*
 * 这道题有两种解法， 栈 和 DP 栈应当是第一个想到的，毕竟有括号，推入栈的时候记住序号即可
 * DP 难在分析情况。。。
 */
class No32_LongestValidParentheses {

public:
    int longestValidParentheses(string s) {
        vector<int> longest(n, 0);
        int max = 0;

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                if(s[i - 1] == '(') {
                    longest[i] = longest[i - 2] + 2;
                    max = max > longest[i] ? max : longest[i];
                } else {   // s[i - 1] == ')'
                    if ( i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '(') {
                        longest[i] = longest[i - 1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                        max = max > longest[i] ? max : longest[i];
                    }
                }


            } else {
                // do nothing for s[i] == '('
            }



        }

        return max;


    }
};
