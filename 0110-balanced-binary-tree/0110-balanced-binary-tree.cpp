/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
   
    int checkBalance(TreeNode* root) {
        if (!root) return 0;

        int leftH = checkBalance(root->left);
        if (leftH == -1) return -1;

        int rightH = checkBalance(root->right);
        if (rightH == -1) return -1;

        if (abs(leftH - rightH) > 1) return -1;

        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};
