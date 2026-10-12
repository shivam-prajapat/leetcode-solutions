class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        for (int x : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((x >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        for (int i = 0; i < k; ++i) {
            long long val = 0;
            for (int j = 0; j < 32; ++j) {
                if (count[j] > 0) {
                    val |= (1LL << j);
                    count[j]--;
                }
            }
            ans = (ans + (val * val) % mod) % mod;
        }
        
        return ans;
    }
};