//
// Created by Qiang Chen on 16/08/2017.
//

//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//        S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//        If there is no such window in S that covers all characters in T, return the empty string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


// 这道题 同No30  No3 可以用窗口思想解决
// 我一开始题目理解有误，以为不能超过，就是有限次，后来发现是可多不可少，而且有可能会重复多次

#include <string>
#include <unordered_map>
using namespace std;
class No76_Hard_MinimunWindowSubstring{
public:
    string minWindow(string s, string t) {
        string result;
        int left = 0;
        unordered_map<char, int> charMap;
        int totalNum = t.length();
        for( int i = 0 ; i < totalNum ; ++i )
            charMap[t[i]]++;

        int count = 0;
        unordered_map<char, int> tempCharMap;
        for( int i = 0 ; i < s.length() ; ++i ) {

            if(charMap[s[i]]) {
                if(count == 0) {
                    left = i;
                }
                tempCharMap[s[i]]++;
                if(tempCharMap[s[i]] <= charMap[s[i]]) {
                    count++;
                } else { // tempCharMap[s[i]] > charMap[s[i]]
                    // 尝试跳过所有无效的和多余的字符
                    while(charMap[s[left]] == 0 || tempCharMap[s[left]] > charMap[s[left]]) {
                        if (tempCharMap[s[left]] > charMap[s[left]]) {
                            tempCharMap[s[left]]--;
                        }
                        left++;
                    }
                }
                if(count == totalNum) {  // get one result
                    if(result.length() == 0 || i - left + 1 < result.length() ) {
                        result = s.substr(left, i - left + 1);
                    }
                }
            }



        }
        return result;
    }
};