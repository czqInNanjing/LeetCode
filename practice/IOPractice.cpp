//
// Created by Qiang Chen on 15/09/2017.
//

#include<fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;
//int main() {
//
//
//
//    ifstream fin("../CMakeLists.txt");
//    string temp = " a  sddd ";
//    trim(temp);
//
//    double a = 0.151613;
//    cout << setprecision(3) << a << endl;
//    int b =131231;
//    cout << hex << b << endl;
//    cout << dec << b << endl;
//    cout << setbase(8) << b << endl;
//
//    cout << temp;
//    while(fin.good() && !fin.eof()) {
//        getline(fin, temp, '(');
//        cout << temp << endl;
//    }
//    fin.close();
//    ofstream fout("sss.txt");
//    if(fout.good()) {
//        cout << "good" << endl;
//        fout << "Hello world";
//    }
//
//    fout.close();
//
//    cout << "File out put finished" << endl;
//}