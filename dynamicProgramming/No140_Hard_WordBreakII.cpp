//
// Created by Qiang Chen on 07/09/2017.
//
#include <vector>
#include <string>
#include <set>
using namespace std;
class No140_Hard_WordBreakII {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        if(s.empty()) return result;
        if(wordDict.empty()) return result;
        vector<bool> dp(s.length() + 1, false);
        vector<vector<string>> resultDp(s.length() + 1, vector<string>());
        set<string> wordSet(wordDict.begin(), wordDict.end());
        dp[0] = true;
        resultDp[0].push_back("");
        // dp[i] = dp[i - j] == true && s(j, i) in wordDict
        for (int i = 1; i <= s.length(); ++i) {

            for (int j = 1; j <= i; ++j) {
                if(dp[i - j] && wordSet.count(s.substr(i - j, j))) {
                    dp[i] = true;
                    vector<string> temp = resultDp[i - j];
                    for (int k = 0; k < temp.size(); ++k) {
                        if(temp[k].length()) {
                            temp[k] += " " + s.substr(i - j, j);
                        } else {
                            temp[k] = s.substr(i - j, j);
                        }
//                        resultDp[i].push_back(temp[k]);
                    }
                    resultDp[i].insert(resultDp[i].end(), temp.begin(), temp.end());

                }
            }


        }

        return resultDp[s.length()];
    }
};
