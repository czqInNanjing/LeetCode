//
// Created by Qiang Chen on 04/09/2017.
//
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <string>
/*





 */
using namespace std;
class No313_Medium_SuperUglyNumber {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int ugly[n];
        ugly[0] = 1;
        vector<int> index(primes.size(), 0);
        vector<int> factors(primes);
        vector<int> minIndex;
        for(int i = 1; i < n ; ++i ) {
            int minNum = factors[0];
            minIndex.clear();
            minIndex.push_back(0);

            for(int j = 1 ; j < factors.size() ; ++j ) {
                if(minNum > factors[j]) {
                    minNum = factors[j];
                    minIndex.clear();
                    minIndex.push_back(j);
                } else if (minNum == factors[j]){
                    minIndex.push_back(j);
                }
            }
            ugly[i] = minNum;
            for (int k = 0; k < minIndex.size(); ++k) {
                factors[minIndex[k]] = primes[minIndex[k]]*ugly[++index[minIndex[k]]];
            }

        }
        for (int k = 0; k < n; ++k) {
            std::cout << ugly[k] << " ";

        }
        return ugly[n - 1];
    }
};
