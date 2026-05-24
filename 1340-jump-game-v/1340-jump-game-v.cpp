class Solution {
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != 0) return dp[i];
        
        int res = 1;
        int n = arr.size();
        
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; ++j) {
            res = max(res, 1 + dfs(j, arr, d, dp));
        }
        
        for (int j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j) {
            res = max(res, 1 + dfs(j, arr, d, dp));
        }
        
        return dp[i] = res;
    }
    
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, arr, d, dp));
        }
        
        return ans;
    }
};