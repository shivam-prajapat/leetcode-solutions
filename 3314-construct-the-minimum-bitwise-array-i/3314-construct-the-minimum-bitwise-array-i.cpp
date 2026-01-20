class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 2) {
                ans[i] = -1;
            } else {
                // Find the position of the first '0' bit starting from the right (LSB)
                // effectively counting the length of the trailing sequence of '1's.
                int c = 0;
                int temp = nums[i];
                while ((temp & 1) == 1) {
                    temp >>= 1;
                    c++;
                }
                
                // The bit to turn off is at index c-1.
                // This corresponds to subtracting 2^(c-1).
                ans[i] = nums[i] - (1 << (c - 1));
            }
        }
        return ans;
    }
};