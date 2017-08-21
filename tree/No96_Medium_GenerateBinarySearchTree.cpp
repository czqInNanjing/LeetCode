//
// Created by Qiang Chen on 20/08/2017.
//

// 这道题其实可以直接用95的思维，但是会超时，所以改用动态规划。。。（其实就是空间换时间）
class No96_Medium_GenerateBinarySearchTree {

public:
    int numTrees(int n) {

        int result[n + 1];
        result[1] = 1;
        int left, right;
        for (int i = 2 ; i <= n ; ++i ) {
            result[i] = 0;
            for (int j = 1; j <= i ; ++j ) {
                left = right = 0;
                if(j - 1 >= 1)
                    left = result[j - 1];
                if(i - j >= 1)
                    right = result[i - j];
                if(left && right)
                    result[i] += left * right;
                else
                    result[i] += left + right;
            }
        }

        return result[n];
    }



};