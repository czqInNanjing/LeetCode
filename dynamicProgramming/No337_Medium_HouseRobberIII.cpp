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

    // 上述解法一有一个问题，没有解决重叠子问题的问题，导致大量重复的计算， DP可以解决重叠子问题，但是以空间为代价
    // 解法2尝试将问题划分为两种情况，从而避免了重复计算，Time Complexity: O(n) Space Complexity: O(1)

    /*
     * 解法2，不是我写的，懒了。。。。。
     */
    //public int rob(TreeNode root) {
    //        int[] res = robSub(root);
    //        return Math.max(res[0], res[1]);
    //    }
    //
    //private int[] robSub(TreeNode root) {
    //        if (root == null) return new int[2];
    //
    //        int[] left = robSub(root.left);
    //        int[] right = robSub(root.right);
    //        int[] res = new int[2];
    //
    //        res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
    //        res[1] = root.val + left[0] + right[0];
    //
    //        return res;
    //    }
};
