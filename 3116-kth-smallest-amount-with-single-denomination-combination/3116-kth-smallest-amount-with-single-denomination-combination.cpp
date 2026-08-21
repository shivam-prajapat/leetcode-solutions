class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int num_subsets = 1 << n;
        vector<long long> lcms(num_subsets);
        vector<int> signs(num_subsets);
        lcms[0] = 1;
        signs[0] = -1;
        
        for (int i = 1; i < num_subsets; ++i) {
            int p = __builtin_ctz(i);
            int prev = i ^ (1 << p);
            lcms[i] = std::lcm(lcms[prev], (long long)coins[p]);
            signs[i] = -signs[prev];
        }

        auto count = [&](long long val) {
            long long total = 0;
            for (int i = 1; i < num_subsets; ++i) {
                total += signs[i] * (val / lcms[i]);
            }
            return total;
        };

        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};