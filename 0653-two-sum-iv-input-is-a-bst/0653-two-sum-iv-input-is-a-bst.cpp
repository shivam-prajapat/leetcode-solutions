class Solution {
public:
void inorder(TreeNode* root, vector<int>& nums) {
if (root == NULL) return;

    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);

    int i = 0;
    int j = nums.size() - 1;

    while (i < j) {
        int sum = nums[i] + nums[j];

        if (sum == k) return true;
        else if (sum > k) j--;
        else i++;
    }

    return false;
}


};
