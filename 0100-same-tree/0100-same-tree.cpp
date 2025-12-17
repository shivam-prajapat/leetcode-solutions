class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, trees are same
        if (p == NULL && q == NULL)
            return true;

        // If one is null and other is not, not same
        if (p == NULL || q == NULL)
            return false;

        // Check current node value and both subtrees
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
