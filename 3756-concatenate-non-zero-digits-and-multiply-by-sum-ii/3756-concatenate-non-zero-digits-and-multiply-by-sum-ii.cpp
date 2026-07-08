class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> sumD(n + 1, 0);
        vector<int> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        
        // Single pass to build all required prefix structures
        for (int i = 1; i <= n; ++i) {
            int d = s[i - 1] - '0';
            
            // 1. Prefix sum of digits
            sumD[i] = sumD[i - 1] + d;
            
            // 2. Prefix count of non-zero digits
            cntN0[i] = cntN0[i - 1] + (d > 0 ? 1 : 0);
            
            // 3. Prefix numeric value of concatenated non-zero digits
            p[i] = (d > 0) ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
            
            // 4. Precompute powers of 10 for rapid shifting later
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Extract features of the specific substring in O(1) time
            int n0 = cntN0[r + 1] - cntN0[l];
            long long sd = sumD[r + 1] - sumD[l];
            
            // Shift out the digits that came before our 'l' boundary
            long long x = (p[r + 1] - p[l] * pow10[n0]) % MOD;
            
            // Handle negative remainders caused by modular subtraction
            if (x < 0) {
                x += MOD;
            }
            
            // Multiply the extracted integer by the digit sum
            ans.push_back((x * sd) % MOD);
        }
        
        return ans;
    }
};