class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        // Loop until the array is sorted in non-decreasing order
        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = -1;
            
            // Find the adjacent pair with the minimum sum
            // We iterate to find the 'leftmost' one (strict < ensures we keep the first occurrence)
            for (int i = 0; i < nums.size() - 1; ++i) {
                int currentSum = nums[i] + nums[i + 1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    idx = i;
                }
            }
            
            // Perform the operation:
            // 1. Replace the left element (idx) with the sum
            // 2. Remove the right element (idx + 1)
            if (idx != -1) {
                nums[idx] = minSum;
                nums.erase(nums.begin() + idx + 1);
                operations++;
            }
        }
        
        return operations;
    }

private:
    // Helper to check if array is non-decreasing
    bool isSorted(const vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};