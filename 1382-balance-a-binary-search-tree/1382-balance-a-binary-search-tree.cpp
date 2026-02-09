class Solution {
public:
    vector<TreeNode*> nodes;

    // Step 1: In-order traversal to get sorted nodes
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    // Step 2: Recursive function to build a balanced BST
    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];
        
        // Recursively build left and right subtrees
        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);
        
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return buildTree(0, nodes.size() - 1);
    }
};