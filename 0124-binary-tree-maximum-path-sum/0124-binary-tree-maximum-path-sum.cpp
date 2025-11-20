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
    int maxSum = INT_MIN;

    // returns max gain from this node
    int maxGain(TreeNode* root) {
        if (!root) return 0;

        // ignore negative paths
        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));

        // best path passing THROUGH node
        int fullPath = root->val + left + right;

        // update global max
        maxSum = max(maxSum, fullPath);

        // return max gain to parent (only one side allowed)
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
