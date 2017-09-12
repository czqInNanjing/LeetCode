//
// Created by Qiang Chen on 12/09/2017.
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1; // 消去最后一个1
            //  d &= -d 是去取出最后一个1
        }
        return dist;
    }
};