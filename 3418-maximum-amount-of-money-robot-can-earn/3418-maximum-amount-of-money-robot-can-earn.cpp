class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int k = 2; 

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));

       
        for (int x = 0; x <= k; x++) {
            if (coins[0][0] >= 0) {
                dp[0][0][x] = coins[0][0];
            } else {
                if (x > 0) dp[0][0][x] = 0;
                else dp[0][0][x] = coins[0][0];
            }
        }



        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int x = 0; x <= k; x++) {

                    int best = INT_MIN;

                    if (i > 0 && dp[i-1][j][x] != INT_MIN) {
                        best = max(best, dp[i-1][j][x] + coins[i][j]);
                    }

                    if (j > 0 && dp[i][j-1][x] != INT_MIN) {
                        best = max(best, dp[i][j-1][x] + coins[i][j]);
                    }

                    dp[i][j][x] = best;

                    if (coins[i][j] < 0 && x > 0) {
                        if (i > 0 && dp[i-1][j][x-1] != INT_MIN) {
                            dp[i][j][x] = max(dp[i][j][x], dp[i-1][j][x-1]);
                        }
                        if (j > 0 && dp[i][j-1][x-1] != INT_MIN) {
                            dp[i][j][x] = max(dp[i][j][x], dp[i][j-1][x-1]);
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;
        for (int x = 0; x <= k; x++) {
            ans = max(ans, dp[m-1][n-1][x]);
        }

        return ans;
    }
};