//
// Created by Qiang Chen on 13/09/2017.
//
#include <string>
#include <stack>
#include <iostream>

using namespace std;
class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return s;
        s = "1[" + s + "]";
        stack<string> sta;

        string temp;
        string result;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == ']') {
                while (sta.top() != "[") {
                    temp.insert(0, sta.top());
                    sta.pop();
                }
                sta.pop();// pop '[';
                int time = stoi(sta.top());
                sta.pop();
                string tempResult = temp;
                while (time-- > 1) tempResult += temp;
                sta.push(tempResult);
                temp.clear();
            }   else if(s[i] == '[') {
                string integer;
                while(!sta.empty() && sta.top()[0] >= '0' && sta.top()[0] <= '9') {
                    integer.insert(0, sta.top());sta.pop();
                }
                sta.push(integer);
                sta.push(string(1, s[i]));
            } else {
                sta.push(string(1, s[i]));
            }


        }





        return sta.top();
    }
};


//int main(){
//    Solution s;
//    cout << s.decodeString("10[a]2[bc]");
//};