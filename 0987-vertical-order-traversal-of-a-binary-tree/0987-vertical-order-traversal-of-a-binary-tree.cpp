
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // Map banaya sorting ke liye
    queue<pair<TreeNode*, pair<int, int>>> q; // Queue me (node, (vertical, level))
    
    q.push({root, {0, 0}}); // Root ko daala
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second; // x=vertical, y=level
        
        nodes[x][y].insert(node->val); // Map me entry maar di
        
        if (node->left) q.push({node->left, {x - 1, y + 1}});   // Left gaya
        if (node->right) q.push({node->right, {x + 1, y + 1}}); // Right gaya
    }
    
    // Map se data nikal ke final answer me daala
    vector<vector<int>> ans;
    for (auto p : nodes) { // Har vertical pe ghoomo
        vector<int> col;
        for (auto q : p.second) { // Har level pe ghoomo
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
};