class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        // Step 1: Sort the array to easily access extremes
        std::sort(nums.begin(), nums.end());
        
        int maxPairSum = 0;
        int n = nums.size();
        
        // Step 2: Use two pointers (i and n-1-i) to form pairs
        for (int i = 0; i < n / 2; ++i) {
            int currentSum = nums[i] + nums[n - 1 - i];
            
            // Step 3: Keep track of the largest sum encountered
            if (currentSum > maxPairSum) {
                maxPairSum = currentSum;
            }
        }
        
        return maxPairSum;
    }
};