
class Solution {
    int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = 316; 
        vector<vector<vector<int>>> small_queries(T);
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= T) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                small_queries[k].push_back(q);
            }
        }
        
        vector<long long> diff(n);
        for (int k = 1; k < T; ++k) {
            if (small_queries[k].empty()) continue;
            for (int i = 0; i < n; ++i) diff[i] = 1;
            
            for (const auto& q : small_queries[k]) {
                int l = q[0], r = q[1], v = q[3];
                int R = l + ((r - l) / k + 1) * k;
                
                diff[l] = (diff[l] * v) % MOD;
                if (R < n) {
                    diff[R] = (diff[R] * modInverse(v)) % MOD;
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (nums[i] * diff[i]) % MOD;
            }
        }
        
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};