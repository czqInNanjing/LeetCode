//
// Created by Qiang Chen on 12/09/2017.
//
/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSumFrom(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum); // 包括起点或者不包括
    }
    int pathSumFrom(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        return (root->val == sum ? 1 : 0) + pathSumFrom(root->left, sum - root->val) + pathSumFrom(root->right, sum - root->val); // 既然包括了起点，那么接下来就不能断，要一直继续
    }

};