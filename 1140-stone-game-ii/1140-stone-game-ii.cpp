class Solution {
    int memo[101][205];
    int suffixSum[101];
    int solve(int i, int m, int n, vector<int>& piles) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffixSum[i];
        if (memo[i][m] != -1) return memo[i][m];
        
        int res = 0;
        for (int x = 1; x <= 2 * m; ++x) {
            res = max(res, suffixSum[i] - solve(i + x, max(m, x), n, piles));
        }
        return memo[i][m] = res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(memo, -1, sizeof(memo));
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        return solve(0, 1, n, piles);
    }
};