class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_f = 0;
        long long min_price = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            max_f = max(max_f, items[i][0]);
            min_price = min(min_price, (long long)items[i][1]);
        }

        vector<int> bonus(n, 0);
        if (max_f <= 2000000) {
            vector<int> freq(max_f + 1, 0);
            for (int i = 0; i < n; ++i) {
                freq[items[i][0]]++;
            }
            vector<int> div_cnt(max_f + 1, 0);
            for (int f = 1; f <= max_f; ++f) {
                if (freq[f] == 0) continue;
                for (int m = f; m <= max_f; m += f) {
                    div_cnt[f] += freq[m];
                }
            }
            for (int i = 0; i < n; ++i) {
                bonus[i] = div_cnt[items[i][0]] - 1;
            }
        } else {
            unordered_map<int, int> freq;
            freq.reserve(n);
            for (int i = 0; i < n; ++i) {
                freq[items[i][0]]++;
            }
            unordered_map<int, int> div_cnt;
            div_cnt.reserve(freq.size());
            for (const auto& [f1, c1] : freq) {
                int cnt = 0;
                for (const auto& [f2, c2] : freq) {
                    if (f2 % f1 == 0) {
                        cnt += c2;
                    }
                }
                div_cnt[f1] = cnt - 1;
            }
            for (int i = 0; i < n; ++i) {
                bonus[i] = div_cnt[items[i][0]];
            }
        }

        long long sum_v = 0;
        for (int i = 0; i < n; ++i) {
            if (items[i][1] <= budget) {
                sum_v += 1LL + bonus[i];
            }
        }

        long long ans = budget / min_price;
        if (budget <= sum_v) {
            int B = budget;
            vector<long long> dp(B + 1, -1);
            dp[0] = 0;
            int max_c = 0;
            for (int i = 0; i < n; ++i) {
                int w = items[i][1];
                if (w > B) continue;
                long long v = 1LL + bonus[i];
                int lim = min(B, max_c + w);
                for (int c = lim; c >= w; --c) {
                    if (dp[c - w] != -1) {
                        dp[c] = max(dp[c], dp[c - w] + v);
                    }
                }
                max_c = lim;
            }
            for (int c = 0; c <= max_c; ++c) {
                if (dp[c] != -1) {
                    ans = max(ans, dp[c] + (budget - c) / min_price);
                }
            }
        } else {
            int V = sum_v;
            long long INF = (long long)budget + 1;
            vector<long long> min_cost(V + 1, INF);
            min_cost[0] = 0;
            int max_v = 0;
            for (int i = 0; i < n; ++i) {
                long long w = items[i][1];
                if (w > budget) continue;
                int v = 1 + bonus[i];
                int lim = max_v + v;
                for (int val = lim; val >= v; --val) {
                    if (min_cost[val - v] + w < min_cost[val]) {
                        min_cost[val] = min_cost[val - v] + w;
                    }
                }
                max_v = lim;
            }
            for (int val = 0; val <= max_v; ++val) {
                if (min_cost[val] <= budget) {
                    ans = max(ans, (long long)val + (budget - min_cost[val]) / min_price);
                }
            }
        }

        return (int)ans;
    }
};