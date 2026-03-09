class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(zero + 1,
            vector<vector<int>>(one + 1, vector<int>(2, 0)));

        for (int i = 1; i <= min(zero, limit); i++)
            dp[i][0][0] = 1;

        for (int j = 1; j <= min(one, limit); j++)
            dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {

                for (int k = 1; k <= min(i, limit); k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i-k][j][1]) % MOD;
                }

                for (int k = 1; k <= min(j, limit); k++) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j-k][0]) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};