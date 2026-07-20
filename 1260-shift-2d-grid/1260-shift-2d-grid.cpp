class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = i * n + j;
                int new_idx = (idx + k) % total;
                ans[new_idx / n][new_idx % n] = grid[i][j];
            }
        }
        
        return ans;
    }
};