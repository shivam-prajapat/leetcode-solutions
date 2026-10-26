class Solution {
    int m, n;
    long long current_sum;
    
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return;
        }
        current_sum += grid[r][c];
        grid[r][c] = 0;
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
    
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    current_sum = 0;
                    dfs(i, j, grid);
                    if (current_sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};