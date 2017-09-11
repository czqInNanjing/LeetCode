//
// Created by Qiang Chen on 10/09/2017.
//
#include <vector>
#include <set>
#include "../tree/No208_Medium_ImplementTrieTree.cpp"
using namespace std;
/**
 * 这道题给我带来了不少的思考，我要好好地记录一下：
 * 1、 首先是Trie，不必多说，实现不难，插入的值应当少，查询的次数应当多。提高回溯的方法是尽早剪枝，当前查找的单词若不出现在任何一个单词的前缀，则跳过
 * 2、 关于Java集合类和C++ STL的比较： STL模板类里面放的都是值不是引用，意味着push进去的时候会复制一份，拿的时候拿到的是引用，无副作用。 Java Collection类放进去的都是引用，会用副作用
 * 3、 但是，Java的String是不可变的，因此放进集合类的String无副作用。 C++的string应当类比Java的StringBuilder/StringBuffer
 * 4、 不要滥用引用，需要注意副作用
 */
class No80_Hard_WordSearchII{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if(board.empty() || board[0].empty() || words.empty()) return result;

        No208_Medium_ImplementTrieTree tree;
        set<string> tempResult;
        for (int i = 0; i < words.size(); ++i) {
            tree.insert(words[i]);
        }
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        string temp;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(tree, tempResult, board, used, temp, i, j);

            }
        }
        return result;
    }

    void dfs(No208_Medium_ImplementTrieTree& trie, set<string>& result, vector<vector<char>>& board, vector<vector<bool>>& used, string word, int x, int y) {

        if( x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || used[x][y] )
            return;

        word += board[x][y];
        if(!trie.startsWith(word)) return;
        if(trie.search(word)) result.insert(word);


        used[x][y] = true;
        dfs(trie, result, board, used, word, x - 1, y);
        dfs(trie, result, board, used, word, x, y - 1);
        dfs(trie, result, board, used, word, x + 1, y);
        dfs(trie, result, board, used, word, x, y + 1);
        used[x][y] = false;


    }
};