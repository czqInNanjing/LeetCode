//
// Created by Qiang Chen on 20/08/2017.
//

#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class No95_Medium_GenerateBinarySearchTreeII {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return vector<TreeNode*>();

        vector<TreeNode*> result;
        generateTrees(result, 1, n);
        return result;
    }

    void generateTrees(vector<TreeNode*> &result, int start, int end) {
        if(start > end) {
            result.push_back(nullptr);
            return;
        }
        if(start == end)  {
            result.push_back(new TreeNode(start));
            return;
        }


        for(int i = start ; i <= end ; ++i ) {
            vector<TreeNode*> leftResult;
            vector<TreeNode*> rightResult;
            generateTrees(leftResult, start, i - 1);
            generateTrees(rightResult, i + 1, end);
            for( auto& lp : leftResult) {
                for( auto& rp : rightResult ) {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = lp;
                    temp->right = rp;
                    result.push_back(temp);
                }
            }
        }
    }
};
