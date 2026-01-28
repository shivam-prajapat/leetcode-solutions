class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[t][i][j] stores min cost to reach (i, j) with t teleports
        // Initialize with a safe "infinity" (INT_MAX / 2 to avoid overflow on add)
        int INF = INT_MAX / 2;
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m, vector<int>(n, INF)));
        
        dp[0][0][0] = 0;
        
        // Maximum possible value in grid as per constraints (usually 10^4 or similar)
        // We will compute suffix minimums over the value range.
        int max_val = 0;
        for(const auto& row : grid) {
            for(int val : row) max_val = max(max_val, val);
        }
        
        for (int t = 0; t <= k; ++t) {
            // 1. Propagate Normal Moves (Right/Down) within the current layer t
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[t][i][j] == INF) continue;
                    
                    int current_cost = dp[t][i][j];
                    
                    // Move Down
                    if (i + 1 < m) {
                        dp[t][i + 1][j] = min(dp[t][i + 1][j], current_cost + grid[i + 1][j]);
                    }
                    // Move Right
                    if (j + 1 < n) {
                        dp[t][i][j + 1] = min(dp[t][i][j + 1], current_cost + grid[i][j + 1]);
                    }
                }
            }
            
            // 2. Propagate Teleports to layer t + 1 (if valid)
            if (t < k) {
                // Find min cost for each value present in the grid at layer t
                vector<int> min_cost_by_val(max_val + 2, INF);
                
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dp[t][i][j] != INF) {
                            int val = grid[i][j];
                            min_cost_by_val[val] = min(min_cost_by_val[val], dp[t][i][j]);
                        }
                    }
                }
                
                // Compute suffix minimum: suffix_min[v] = min(min_cost_by_val[x]) for x >= v
                // This represents the cheapest cost to be at ANY cell with value >= v
                int current_suffix_min = INF;
                vector<int> suffix_min(max_val + 2, INF);
                for (int v = max_val; v >= 0; --v) {
                    current_suffix_min = min(current_suffix_min, min_cost_by_val[v]);
                    suffix_min[v] = current_suffix_min;
                }
                
                // Update layer t+1 using teleport costs
                // We can teleport to (i, j) from any cell with value >= grid[i][j]
                // Cost of teleport is 0, so new cost is just the cost of the source.
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int val = grid[i][j];
                        if (suffix_min[val] != INF) {
                            dp[t + 1][i][j] = min(dp[t + 1][i][j], suffix_min[val]);
                        }
                    }
                }
            }
        }
        
        // The answer is the minimum cost to reach the bottom-right cell
        // using any number of teleports from 0 to k.
        int ans = INF;
        for (int t = 0; t <= k; ++t) {
            ans = min(ans, dp[t][m - 1][n - 1]);
        }
        
        return ans;
    }
};