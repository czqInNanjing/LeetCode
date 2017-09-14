//
// Created by Qiang Chen on 16/08/2017.
//

// 不需要怀疑你自己，智商确实还可以，解决这道题 不到一个小时，轻轻松松，思路清晰，一次AC！！！！
// 回溯法，无需多言
#include <vector>
using namespace std;
class No37_Hard_SudokuSolver {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, int startX, int startY) {
        for( int i = startX ; i < 9 ; ++i ) {
            for( int j = startY ; j < 9; ++j ) {
                if(board[i][j] == '.') {
                    bool used[9] = {0};
                    int boxX = i / 3 * 3;
                    int boxY = j / 3 * 3;
                    for(int m = 0 ; m < 9 ; m++ ) {
                        // check row
                        if(board[i][m] != '.')
                            used[board[i][m] - '0' - 1] = 1;
                        // check column
                        if(board[m][j] != '.')
                            used[board[m][j] - '0' - 1] = 1;
                        // check box
                        if(board[boxX + m / 3 ][boxY + m % 3] != '.')
                            used[board[boxX + m / 3 ][boxY + m % 3] - '0' - 1] = 1;
                    }
                    for(int k = 0 ; k < 9 ; k++ ) {
                        if(!used[k]) {
                            board[i][j] = (char) ( k + '0' + 1);
                            if(solveSudoku(board, startX, startY)) {
                                return true;
                            }
                        }
                    }
                    board[i][j] = '.';
                    return false;

                }
            }
        }
        return true;
    }
};