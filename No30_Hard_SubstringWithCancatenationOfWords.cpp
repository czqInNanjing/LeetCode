//
// Created by Qiang Chen on 8/16/17.
//
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
// Key : Hashmap


class No30_Hard_SubstringWithCancatenationOfWords{
public:
    /*
     * 比较快的方法， AC 26ms，快了10倍
     * 核心思想是维护一个窗口（参考No3），一次移动一个窗口的距离，如果不符合的话就前进一个窗口的距离   一个单词不会被访问超过两次，大大加快速度
     * 如果次数超过map里的次数的话，就右移窗口直到次数-1（和不出现重复字符本质类似，那个所有字符只出现1次）
     */
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = S.size(), cnt = L.size();
        if (n <= 0 || cnt <= 0) return ans;

        // init word occurence
        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i) dict[L[i]]++;

        // travel all sub string combinations
        int wl = L[0].size();
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl) {
                string str = S.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str])
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = S.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[S.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                    // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }

        return ans;
    }







    /*
     * 比较慢的方法， AC 209ms   疑问：C++里面map找不到的key返回值究竟是什么？一脸懵逼
     */
    //  其实就是从左到右遍历，看看依次出现的单词次数是否满足给定的单词次数即可，用hashmap来存储需要出现的次数

//    vector<int> findSubstring(string s, vector<string>& words) {
//        unordered_map<string, int>  wordTimes;
//        int totalCounts = words.size();
//        int wordLen = words[0].length();
//
//        for(int i = 0 ; i < words.size() ; ++i ) {
//            wordTimes[words[i]]++;
//        }
//
//        vector<int> result;
//        for (int i = 0 ; i < s.length() - totalCounts * wordLen + 1 ; ++i ) {
//            unordered_map<string, int> seen;
//            int tempCount = 0;
//            while(true) {
//                string nextWord = s.substr(i + tempCount*wordLen, wordLen);
//
//                if( wordTimes.find(nextWord) != wordTimes.end() && seen[nextWord] != wordTimes[nextWord] ) {
//                    seen[nextWord]++;
//                    tempCount++;
//                    if(tempCount == totalCounts) {
//                        result.push_back(i);
//                        break;
//                    }
//                } else {
//                    seen.clear();
//                    break;
//                }
//
//
//            }
//
//
//
//
//
//        }
//
//
//        return result;
//
//
//    }
};