//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <string>
using namespace std;
class No79_Medium_WordSearch {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        if(word.empty()) return true;
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        bool result = false;
        for(int i = 0; i < board.size(); ++i) {
            for( int j = 0; j < board[0].size(); ++j) {
                if(exist(board, used, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& used, string& word, int start, int x, int y) {
        if(start >= word.length()) return true;

        if( x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || used[x][y] || board[x][y] != word[start])
            return false;

        used[x][y] = true;
        if(exist(board, used, word, start + 1, x - 1, y) || exist(board, used, word, start + 1, x, y - 1) ||
           exist(board, used, word, start + 1, x + 1, y) || exist(board, used, word, start + 1, x, y + 1) )
            return true;

        used[x][y] = false;
        return false;


    }
};
