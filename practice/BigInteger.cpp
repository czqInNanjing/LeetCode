//
// Created by Qiang Chen on 15/09/2017.
//
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct BigInteger {
    const static int BASE = 100000000;
    const static int WIDTH = 8;
    vector<int> s;
    BigInteger(long long num = 0) {*this = num;}
    BigInteger(string s) {*this = s;}
    BigInteger& operator = (long long num) {
        s.clear();

        do {
            s.push_back(num%BASE);
            num = num / BASE;
        } while (num > 0);
        return *this;
    }

    BigInteger& operator = (string str) {
        int len = (str.length() - 1) / WIDTH + 1;
        s.clear();
        for (int i = 0; i < len; ++i) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            int x = stoi(str.substr(start, end - start));
            s.push_back(x);
        }
        return *this;
    }

    friend ostream& operator<< (ostream& os, const BigInteger& integer) {
        os << integer.s.back();
        for(int i = integer.s.size() - 2; i >= 0 ; --i) {
            os << integer.s[i];
        }
        return os;
    }
    friend istream& operator>> (istream& in, BigInteger& integer) {
        string s;
        if(!(in >> s)) return in;
        integer = s;
        return in;
    }
};

//int main() {
////    string s = "123456789";
////    BigInteger big = s;
////    BigInteger bi2 = 123;
////    cout << big << bi2;
//    string temp = "12345";
//
//    cout << atoi(temp.c_str());
//
//}
