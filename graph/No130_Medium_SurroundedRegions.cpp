//
// Created by Qiang Chen on 06/09/2017.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
// 血与泪的教训。。。。。bfs遍历的时候一定要记得把状态改完再推进队列里面，不然的话很有可能会有重复的出现。。。。。。。。。。。。。。。。
class No130_Medium_SurroundedRegions{
public:

    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();


        for(int j = 0 ; j < n; ++j) {
            if(board[0][j] == 'O')
                bfs(board, 0, j);
            if(board[m - 1][j] == 'O')
                bfs(board, m - 1, j);
        }
        for(int i = 0 ; i < m; ++i) {
            if(board[i][0] == 'O')
                bfs(board, i, 0);
            if(board[i][n - 1] == 'O')
                bfs(board, i, n - 1);
        }

        for(int i = 0 ; i < m ; ++i) {
            for(int j = 0 ; j < n; ++j) {
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void bfs(vector<vector<char>>& board, int startX, int startY) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> que;
        que.push(make_pair(startX, startY));
        board[startX][startY] = 'S';
        while(!que.empty()) {

            pair<int, int>& point = que.front();
            que.pop();

            if(point.first != 0 && board[point.first - 1][point.second] == 'O') {
                que.push(make_pair(point.first - 1, point.second));
                board[point.first - 1][point.second] = 'S';
            }

            if(point.second != 0 && board[point.first][point.second - 1] == 'O') {
                que.push(make_pair(point.first, point.second - 1));
                board[point.first][point.second - 1] = 'S';
            }

            if(point.first != m - 1 && board[point.first + 1][point.second] == 'O') {
                que.push(make_pair(point.first + 1, point.second));
                board[point.first + 1][point.second] = 'S';
            }

            if(point.second != n - 1 && board[point.first][point.second + 1] == 'O') {
                que.push(make_pair(point.first, point.second + 1));
                board[point.first][point.second + 1] = 'S';
            }
//            以下为血与泪的教训代码。。。。。。。。。。。。。。叉！！！！！！！！！

//            while(!que.empty()) {
//
//                pair<int, int>& point = que.front();
//                que.pop();
//                board[point.first][point.second] = 'S';
//                if(point.first != 0 && board[point.first - 1][point.second] == 'O')
//                    que.push(make_pair(point.first - 1, point.second));
//                if(point.second != 0 && board[point.first][point.second - 1] == 'O')
//                    que.push(make_pair(point.first, point.second - 1));
//                if(point.first != m - 1 && board[point.first + 1][point.second] == 'O')
//                    que.push(make_pair(point.first + 1, point.second));
//                if(point.second != n - 1 && board[point.first][point.second + 1] == 'O')
//                    que.push(make_pair(point.first, point.second + 1));
//
//
//
//            }



        }

    }


//    void solve(vector<vector<char>>& board) {
//        if(board.empty() || board[0].empty()) return;
//        int m = board.size();
//        int n = board[0].size();
//
//        vector<vector<char>> newBoard;
//        newBoard.push_back(vector<char>(n + 2, 'O'));
//        for(int i = 0; i < m ; ++i) {
//            vector<char> temp = board[i];
//            temp.insert(temp.begin(), 'O');
//            temp.push_back('O');
//            newBoard.push_back(temp);
//        }
//        newBoard.push_back(vector<char>(n + 2, 'O'));
//
//        bfs(newBoard);
//
//        for(int i = 0 ; i < m ; ++i) {
//            for(int j = 0 ; j < n; ++j) {
//                if(newBoard[i + 1][j + 1] != 'S')
//                    board[i][j] = 'X';
//            }
//        }
//    }
//    void bfs(vector<vector<char>>& board) {
//        int m = board.size();
//        int n = board[0].size();
//
//        queue<pair<int, int>> que;
//        que.push(make_pair(0, 0));
//        while(!que.empty()) {
//
//            pair<int, int>& point = que.front();
//            que.pop();
//            board[point.first][point.second] = 'S';
//            if(point.first != 0 && board[point.first - 1][point.second] == 'O')
//                que.push(make_pair(point.first - 1, point.second));
//
//            if(point.second != 0 && board[point.first][point.second - 1] == 'O')
//                que.push(make_pair(point.first, point.second - 1));
//
//            if(point.first != m - 1 && board[point.first + 1][point.second] == 'O')
//                que.push(make_pair(point.first + 1, point.second));
//
//            if(point.second != n - 1 && board[point.first][point.second + 1] == 'O')
//                que.push(make_pair(point.first, point.second + 1));
//
//
//
//        }
//
//    }
};
