//
// Created by Qiang Chen on 06/09/2017.
//
#include <string>
#include <vector>
using namespace std;
class No131_Medium_PalindromePartitioning{
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.empty()) return result;
        vector<string> temp;
        partition(result, temp, s, 0);
        return result;
    }
    void partition(vector<vector<string>>& result, vector<string>& temp, string s, int start) {
        if(start >= s.size()) result.push_back(temp);

        for(int i = start; i < s.size(); i++ ) {
            if(isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                partition(result, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
