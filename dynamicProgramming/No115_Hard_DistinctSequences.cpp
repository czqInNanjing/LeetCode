//
// Created by Qiang Chen on 05/09/2017.
//
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class No115_Hard_DistinctSequences{
public:
    /*
     * 隔了八天，自己写的代码都不认识了。。。。。。。
     * dp[i][j] 代表s第（0 ~ i - 1） t 第 （0 ~ j） 字符不同的数量
     */
    int numDistinct(string s, string t) {
        if(s.empty() || t.empty()) return 0;
        if(s.length() < t.length()) return 0;

        vector<unordered_map<int , int>> dp(s.length() + 1, unordered_map<int, int>());
        unordered_map<char, vector<int>> charMap;
        for (int i = 0; i < t.length(); ++i) {
            charMap[t[i]].push_back(i);
        }


        for (int i = 0; i < t.length(); ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i < s.length() + 1; ++i) {

            dp[i] = dp[i - 1];
            if(charMap.count(s[i - 1])) {
                vector<int> appear = charMap[s[i - 1]];

                for (int j = 0; j < appear.size(); ++j) {
                    if (appear[j] == 0) dp[i][0] += 1;
                    else dp[i][appear[j]] += dp[i - 1][appear[j] - 1];
                }



            }
        }

        return dp[s.length()][t.length() - 1];
    }



    /*
    // 回溯法， TLE
    int numDistinct(string s, string t) {
        if(s.empty() || t.empty()) return 0;
        if(s.length() < t.length()) return 0;
        int result = 0;

        numDistinct(result, s, t, 0 , 0);
        return result;
    }

    void numDistinct(int &result, string& s, string& t, int sPointer, int tPointer) {
        if(sPointer == s.size() && tPointer == t.size()) {result++; return;}
        if(sPointer == s.size()) return;
        if(s.size() - sPointer < t.size() - tPointer) return;

        if(s[sPointer] == t[tPointer]) {
            numDistinct(result, s, t, sPointer + 1, tPointer + 1);
            numDistinct(result, s, t, sPointer + 1, tPointer);
        } else {
            numDistinct(result, s, t, sPointer + 1, tPointer);
        }



    }
     */
};
