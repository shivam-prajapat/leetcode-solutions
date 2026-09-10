class Solution {
    int result = 0;
    
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        
        if (sum / count == root->val) {
            result++;
        }
        
        return {sum, count};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }
};