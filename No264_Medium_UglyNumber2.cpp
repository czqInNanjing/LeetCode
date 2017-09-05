//
// Created by Qiang Chen on 04/09/2017.
//
#include <vector>
#include <set>
#include <queue>
#include <iostream>
/*
紫书上的答案是错的，有可能第N个数不是第N个丑数，所以不对
 (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …
 维护三个index，每次取到该数，该数便往下走一个




 */
using namespace std;
class No264_Medium_UglyNumber2{
public:
    int nthUglyNumber(int n) {

        int ugly[n];
        ugly[0] = 1;
        int index2 = 0 , index3 = 0 , index5 = 0;
        int factor2 = 2, factor3= 3 , factor5 = 5;
        for(int i = 1 ; i < n ; ++i ) {
            int minNum = min(factor2, min(factor3, factor5));
            ugly[i] = minNum;
            if(minNum == factor2)
                factor2 = 2*ugly[++index2];
            if(minNum == factor3)
                factor3 = 3*ugly[++index3];
            if(minNum == factor5)
                factor5 = 5*ugly[++index5];
        }
        for (int k = 0; k < n; ++k) {
            std::cout << ugly[k] << " ";

        }
        return ugly[n - 1];
    }
};