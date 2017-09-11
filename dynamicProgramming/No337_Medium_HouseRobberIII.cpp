//
// Created by Qiang Chen on 11/09/2017.
//
#include <algorithm>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class No337_Medium_HouseRobberIII{
public:
    // 解法一： 暴力求解：DFS，
    //        AC 1186ms
    int rob(TreeNode* root) {
        return rob(root, true);
    }

    int rob(TreeNode* root, bool canChoose) {
        if(!root) return 0;
        if(canChoose) {
            return max(rob(root->left, false) + rob(root->right, false) + root->val, rob(root->left, true) + rob(root->right, true));
        } else {
            return rob(root->left, true) + rob(root->right, true);
        }
    }


    /*
     * 解法一：版本2：错误版本 WA
     * 尝试用map改良，但是WA, 因为map[root]有两种状态，一是被选的，二是不被选的，不符合DP的原则：与如何到达当前状态无关，事实上是有关的，所以改良为版本3
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> treeMap;
        return rob(root, true, treeMap);
    }

    int rob(TreeNode* root, bool canChoose, unordered_map<TreeNode*, int>& map) {
        if(!root) return 0;
        if(map.count(root)) return map[root];
        if(canChoose) {
            return map[root] = max(rob(root->left, false, map) + rob(root->right, false, map) + root->val, rob(root->left, true, map) + rob(root->right, true, map));
        } else {
            return map[root] = rob(root->left, true, map) + rob(root->right, true, map);
        }
    }
    */

    /*
     * 解法一：版本3：DP版本  AC 16ms
     * yesMap 表示当前root节点可选的情况下， nomap表示当前root节点不可选的情况下
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> yesMap;
        unordered_map<TreeNode*, int> noMap;
        return rob(root, true, yesMap, noMap);
    }

    int rob(TreeNode* root, bool canChoose, unordered_map<TreeNode*, int>& yesMap, unordered_map<TreeNode*, int>& noMap) {
        if(!root) return 0;
        if(canChoose && yesMap.count(root)) return yesMap[root];
        if(!canChoose && noMap.count(root)) return noMap[root];
        if(canChoose) {
            return yesMap[root] = max(rob(root->left, false, yesMap, noMap) + rob(root->right, false, yesMap, noMap) + root->val, rob(root->left, true, yesMap, noMap) + rob(root->right, true, yesMap, noMap));
        } else {
            return noMap[root] = rob(root->left, true, yesMap, noMap) + rob(root->right, true, yesMap, noMap);
        }
    }
    */
};
