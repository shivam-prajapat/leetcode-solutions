class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            // Case 1: Even prime (2) is impossible
            if (val == 2) {
                ans[i] = -1;
            } 
            // Case 2: Odd primes
            else {
                // Find the lowest zero bit mask.
                // Example: val = 7 (0111), val + 1 = 8 (1000)
                // ~val = ...1000
                // (val + 1) & ~val = 1000 (The bit at index 3)
                int lowest_zero_bit = (val + 1) & ~val;
                
                // We want to flip the bit immediately to the right of the lowest zero.
                // So we shift right by 1.
                int subtractor = lowest_zero_bit >> 1;
                
                ans[i] = val ^ subtractor;
            }
        }
        
        return ans;
    }
};