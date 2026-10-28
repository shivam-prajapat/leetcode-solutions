class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> dp(n, vector<bool>(1024, false));
        
        int start_val = grid[0][0];
        dp[0][start_val] = true;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                vector<bool> next_dp(1024, false);
                int val = grid[i][j];
                
                for (int v = 0; v < 1024; ++v) {
                    if (i > 0 && dp[j][v]) {
                        next_dp[v ^ val] = true;
                    }
                    if (j > 0 && dp[j - 1][v]) {
                        next_dp[v ^ val] = true;
                    }
                }
                
                dp[j] = next_dp;
            }
        }
        
        for (int v = 0; v < 1024; ++v) {
            if (dp[n - 1][v]) {
                return v;
            }
        }
        
        return 0;
    }
};