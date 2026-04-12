class Solution {
public:
    int dist(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<int> dp(26, 0);
        int total = 0;

        for (int i = 1; i < n; i++) {
            int prev = word[i - 1] - 'A';
            int cur = word[i] - 'A';
            int d = dist(prev, cur);
            total += d;

            vector<int> new_dp = dp;
            for (int j = 0; j < 26; j++) {
                new_dp[prev] = max(new_dp[prev], dp[j] + d - dist(j, cur));
            }
            dp = new_dp;
        }

        int best = 0;
        for (int x : dp) best = max(best, x);

        return total - best;
    }
};