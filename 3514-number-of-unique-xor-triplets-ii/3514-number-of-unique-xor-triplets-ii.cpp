class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }
        
        int p = 1;
        while (p <= max_val) {
            p <<= 1;
        }
        
        vector<bool> result(p, false);
        vector<bool> seen_pair(p, false);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int k = i; k < n; ++k) {
                seen_pair[nums[i] ^ nums[k]] = true;
            }
            for (int v = 0; v < p; ++v) {
                if (seen_pair[v]) {
                    result[nums[i] ^ v] = true;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < p; ++i) {
            if (result[i]) count++;
        }
        return count;
    }
};