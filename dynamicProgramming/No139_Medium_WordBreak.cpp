//
// Created by Qiang Chen on 07/09/2017.
//
#include <vector>
#include <string>
#include <set>
using namespace std;
class No139_Medium_WordBreak{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        if(wordDict.empty()) return false;
        vector<bool> dp(s.length() + 1, false);
        set<string> wordSet(wordDict.begin(), wordDict.end());
        dp[0] = true;
        // dp[i] = dp[i - j] == true && s(j, i) in wordDict
        for (int i = 1; i <= s.length(); ++i) {

            for (int j = 1; j <= i; ++j) {
                if(dp[i - j] && wordSet.count(s.substr(i - j, j))) {
                    dp[i] = true;
                    break;
                }
            }


        }

        return dp[s.length()];

    }


    // TLE......习惯了。。。。
    /*
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        if(wordDict.empty()) return false;
        unordered_map<int, vector<string>> wordMap;
        for (int i = 0; i < wordDict.size(); ++i) {
            wordMap[wordDict[i].length()].push_back(wordDict[i]);
        }
        return wordBreak(s, wordMap, 0);
    }

    bool wordBreak(string& s, unordered_map<int, vector<string>>& wordMap, int start) {
        if(start >= s.length()) return true;

        for (int i = start; i < s.length(); ++i) {
            string temp = s.substr(start, i - start + 1);
            if (find(wordMap[temp.length()].begin(), wordMap[temp.length()].end(), temp) != wordMap[temp.length()].end()) {
                if(wordBreak(s, wordMap, i + 1))
                    return true;
            }
        }
        return false;
    }
     */
};
