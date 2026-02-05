class Solution {
public:
    std::vector<int> constructTransformedArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            // Case 1: nums[i] is 0, value stays the same
            if (nums[i] == 0) {
                result[i] = nums[i];
            } 
            else {
                // Calculate the target index using the circular array formula
                // (i + jump) % n might be negative, so we add n and % again
                int targetIndex = (i + (nums[i] % n) + n) % n;
                result[i] = nums[i + (targetIndex - i)]; // Which is just nums[targetIndex]
                
                // More simply:
                result[i] = nums[targetIndex];
            }
        }

        return result;
    }
};