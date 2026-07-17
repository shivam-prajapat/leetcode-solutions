class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }
        
        vector<int> freq(max_val + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }
        
        vector<int> countDivisor(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                countDivisor[i] += freq[j];
            }
        }
        
        vector<long long> countGcdPair(max_val + 1, 0);
        for (int gcd = max_val; gcd >= 1; --gcd) {
            long long c = countDivisor[gcd];
            countGcdPair[gcd] = c * (c - 1) / 2;
            for (int largerGcd = 2 * gcd; largerGcd <= max_val; largerGcd += gcd) {
                countGcdPair[gcd] -= countGcdPair[largerGcd];
            }
        }
        
        vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix[i] = prefix[i - 1] + countGcdPair[i];
        }
        
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            long long q = queries[i];
            int left = 1;
            int right = max_val;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (prefix[mid] > q) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = left;
        }
        
        return ans;
    }
};