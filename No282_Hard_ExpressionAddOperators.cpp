//
// Created by Qiang Chen on 05/09/2017.
//

/*
 * 这道题有毒！！！！！！！！！！！！！！！！！！！！
 * 其实不难，就是考虑几点：
 * 1. 连续0的处理，如果第一位是0的话跳过
 * 2. 乘法后置，用存储一个临时值来保存
 * 3. 可以多个字符组成一个数
 *
 * string处理要点
 * substr 是从i开始的N个字符，不是开始到结束
 * to_string  stoi  的使用
 * 如果不是C++11 的话， 可以用 stringstream
 * 或atoi   atoi(s.c_str())
 */


#include <string>
#include <vector>
typedef long long LL;
using namespace std;
class No282_Hard_ExpressionAddOperators{
public:

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(!num.length()) return result;
        addOperators(result, num, 0, 0, 0, target, "");
        return result;
    }

    /*
     * position: tempChar
     * val     : accumulate value
     * last val: val last add/minus/multiply
     * temp    : temp result
     */
    void addOperators(vector<string>& result, string& num, int position, LL val, LL lastVal, int target, string temp) {
        if(position >= num.size() ) {
            if(val == target) result.push_back(temp);
            return;
        }

        for (int i = position ; i < num.size(); ++i) {
            if(i != position  && num[position] == '0') break;
            LL tempOperand = stol(num.substr(position, i - position + 1));
            if(position == 0)
                addOperators(result, num, i + 1, val + tempOperand, tempOperand, target, temp + to_string(tempOperand));
            else {
                addOperators(result, num, i + 1, val + tempOperand, tempOperand, target, temp + "+" + to_string(tempOperand));  // do add
                addOperators(result, num, i + 1, val - tempOperand, -tempOperand, target, temp + "-" + to_string(tempOperand)); // do minus
                addOperators(result, num, i + 1, val - lastVal + lastVal*tempOperand, lastVal*tempOperand, target, temp + "*" + to_string(tempOperand));
            }

        }


    }












//    const static string OPERATORS[3] = {"+", "-", "*"} ;
//    const static int OP_NUM = 3;
//    vector<string> addOperators(string num, int target) {
//        if(!num.length()) return vector<string>();
//
//        vector<string> result;
//        vector<int> digits;
//        for(int i = 0 ; i < num.length(); ++i ){
//            digits.push_back(num[i] - '0');
//        }
//        addOperators(result, digits, 1, digits[0], target, to_string(digits[0]));
//        return result;
//    }
//    void addOperators(vector<string>& result, vector<int>& digits, int position, int val, int target, string temp) {
//        if(position >= digits.size() ) {
//            if(val == target) result.push_back(temp);
//            return;
//        }
//
//        for(int i = 0 ; i < OP_NUM; ++i ) {
//            computeVal(val, i, digits[position]);
//            addOperators(result, digits, position + 1, val, target, temp + OPERATORS[i] + to_string(digits[position]));
//
//            temp = temp.substr(0, temp.length() - 2);
//        }
//    }
//    void computeVal(int& val, int op, int other) {
//        switch(op) {
//            case 0: val += other; return;
//            case 1: val -= other; return;
//            case 2: val *= other; return;
//            default: return;
//        }
//    }
};
