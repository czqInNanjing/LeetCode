//
// Created by Qiang Chen on 05/09/2017.
//
#include <string>
#include <vector>
// 用数组来记忆出现的数量，hashtable题型
using namespace std;
class No299_Medium_BullsAndCows{
public:
    string getHint(string s, string g) {
        int bulls = 0;
        int cows = 0;
        vector<int> numbers(10, 0);
        for(int i = 0 ; i < s.length(); ++i ) {
            if(s[i] == g[i])
                bulls++;
            else {
                if(numbers[s[i] - '0']-- > 0) cows++;
                if(numbers[g[i] - '0']++ < 0) cows++;
            }

        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
