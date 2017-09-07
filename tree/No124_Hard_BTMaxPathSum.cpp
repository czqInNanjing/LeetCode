//
// Created by Qiang Chen on 06/09/2017.
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
// 这道题是求路径和不是路径的数量，一开始就理解错了
// 递归求解，两种情况，一种是root结点作为转折点，即作为路径的中间，另一种是继续向上
// 子方法返回结束语该节点的最大路径值
// 在子方法中同时统计通过该节点的最大路径值，注意负数，所以要排除负数。
class No124_Hard_BTMaxPathSum{

public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSum(root,result);
        return result;
    }

    int maxPathSum(TreeNode* root, int& result) {
        if (!root) return 0;
        int l = max(0, maxPathSum(root->left, result));
        int r = max(0, maxPathSum(root->right, result));
        result = max(result, l + r + root->val);
        return root->val + max(l, r);
    }
};
