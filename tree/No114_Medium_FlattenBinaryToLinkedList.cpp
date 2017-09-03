//
// Created by Qiang Chen on 03/09/2017.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class No114_Medium_FlattenBinaryToLinkedList {
public:
    void flatten(TreeNode* root) {
        flatten(root, nullptr);
    }

    TreeNode* flatten(TreeNode* root, TreeNode* next) {
        if(!root)
            return next;
        root->right = flatten(root->left, flatten(root->right, next));
        root->left = nullptr;
        return root;
    }


    /*
     *
     *
     *
     *
     *
     *
    一开始写的复杂的代码，自己都受不了，结束条件要好爱好思考来着
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root, nullptr);
    }

    TreeNode* flatten(TreeNode* root, TreeNode* next) {
        if(!root)
            return nullptr;
        if(root->left && root-> right) {
            root->right = flatten(root->right, next);
            root->right = flatten(root->left, root->right);
            root->left = nullptr;
        } else if(!root->left && !root->right ) {
            root->right = next;
        } else if(!root->right) {
            root->right = flatten(root->left, next);
            root->left = nullptr;
        } else {
            root->right = flatten(root->right, next);
        }
        return root;

    }
     *
     */
};
