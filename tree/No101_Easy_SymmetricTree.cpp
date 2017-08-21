//
// Created by Qiang Chen on 20/08/2017.
//




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };


class No101_Easy_SymmetricTree {
public:
    // 解法一： 先复制一个对称的树，再看看他们想不想等 ，，，， 慢



    bool isSymmetric(TreeNode* root) {
        TreeNode *symmetricTree = reverseTree(root);
        return isSameTree(symmetricTree, root);
    }
    TreeNode *reverseTree(TreeNode *root) {

        if(!root)
            return nullptr;
        else {
            TreeNode *temp =  new TreeNode(root->val);
            temp->left = reverseTree(root->right);
            temp->right = reverseTree(root->left);
            return temp;
        }
        return nullptr;
    }



    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( !p && !q )
            return true;

        if( !p || !q)
            return false;

        if( p->val == q->val ) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }


    // 解法2  递归解法
    /*

public boolean isSymmetric(TreeNode root) {
    return root==null || isSymmetricHelp(root.left, root.right);
}

private boolean isSymmetricHelp(TreeNode left, TreeNode right){
    if(left==null || right==null)
        return left==right;
    if(left.val!=right.val)
        return false;
    return isSymmetricHelp(left.left, right.right) && isSymmetricHelp(left.right, right.left);
}

     */
};
