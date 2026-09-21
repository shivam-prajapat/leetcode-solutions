class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int x : nums) {
            vector<long long> next_dp(k, 0);
            int val = (x % k + k) % k;
            
            
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (1LL * r * val) % k;
                    next_dp[new_rem] += dp[r];
                }
            }
            
           
            next_dp[val]++;
            
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }
            
            dp = move(next_dp);
        }
        
        return result;
    }
};