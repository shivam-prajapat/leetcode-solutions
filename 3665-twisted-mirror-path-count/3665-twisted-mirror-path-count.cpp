class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
        
        if (n > 1) dp[0][1][0] = 1;
        if (m > 1) dp[1][0][1] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                if (grid[i][j] == 0) {
                    int paths = dp[i][j][0] + dp[i][j][1];
                    if (paths >= MOD) paths -= MOD;
                    
                    if (i == m - 1 && j == n - 1) {
                        return paths;
                    }
                    
                    if (j + 1 < n) {
                        dp[i][j + 1][0] += paths;
                        if (dp[i][j + 1][0] >= MOD) dp[i][j + 1][0] -= MOD;
                    }
                    if (i + 1 < m) {
                        dp[i + 1][j][1] += paths;
                        if (dp[i + 1][j][1] >= MOD) dp[i + 1][j][1] -= MOD;
                    }
                } else {
                    if (i + 1 < m) {
                        dp[i + 1][j][1] += dp[i][j][0];
                        if (dp[i + 1][j][1] >= MOD) dp[i + 1][j][1] -= MOD;
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1][0] += dp[i][j][1];
                        if (dp[i][j + 1][0] >= MOD) dp[i][j + 1][0] -= MOD;
                    }
                }
            }
        }
        
        return 0;
    }
};