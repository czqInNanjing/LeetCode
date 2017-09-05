//
// Created by Qiang Chen on 05/09/2017.
//
#include <vector>
#include <deque>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class No103_Medium_ZigZagOrderTraversal{

public:

    // 我大概是石乐志，明明直接插入的时候变一下方式就行的，居然用了双端队列。。。石乐志
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL)
            return result;

        bool ifLeftToRight = true;
        std::queue<TreeNode*> frontier;
        frontier.push(root);

        while (!frontier.empty()) {
            int size = frontier.size();
            vector<int> level;
            for (int i = 0; i< size; i++) {
                TreeNode* node = frontier.front();
                frontier.pop();
                if (node->left)
                    frontier.push(node->left);
                if (node->right)
                    frontier.push(node->right);
                if (ifLeftToRight) {
                    level.push_back(node->val);
                } else {
                    level.insert(level.begin(), node->val);
                }
            }
            result.push_back(level);
            ifLeftToRight = !ifLeftToRight;
        }

        return result;
    }
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        deque<TreeNode*> queue;
        bool leftToRight = true;
        int levelSize = 1;
        int nextLevel = 0;
        int count = 0;
        queue.push_back(root);
        vector<int> level;
        while (!queue.empty()) {
            TreeNode* val;
            count++;
            if(leftToRight) {
                val = queue.front();
                queue.pop_front();
                level.push_back(val->val);
                if(val->left) {queue.push_back(val->left); nextLevel++;}
                if(val->right) {queue.push_back(val->right); nextLevel++;}
            } else {
                val = queue.back();
                queue.pop_back();
                level.push_back(val->val);
                if(val->right) {queue.push_front(val->right); nextLevel++;}
                if(val->left) {queue.push_front(val->left); nextLevel++;}
            }
            if(count == levelSize) {
                count = 0;
                levelSize = nextLevel;
                nextLevel = 0;
                leftToRight = !leftToRight;

                result.push_back(level);
                level.clear();
            }
        }
        return result;
    }

    */

};
