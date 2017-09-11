//
// Created by Qiang Chen on 09/09/2017.
//
#include <vector>
using namespace std;
class No73_Medium_SetMatrixZeros{
void setZeroes(vector<vector<int> > &matrix) {
    bool col0 = true, rows = matrix.size(), cols = matrix[0].size();
    // 技巧：将行和列的状态存储在行的第一个元素和列的第一个元素
    // 问题在于第0行和第0列，状态都存在 a[0][0]会出现重复，所以需要一个额外的元素来存储状态
    // 第二轮更新只需要根据状态进行更新就可
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = false;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (!col0) matrix[i][0] = 0;
    }
}
};
