class Solution {
public:
    long long minRemoval(vector<int>& nums, int k) {
        // Step 1: Sort the array to handle min and max easily
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int max_kept = 0;
        int j = 0;
        
        // Step 2: Sliding Window
        // 'i' represents the start of the window (minimum element)
        // 'j' represents the end of the window (maximum element)
        for (int i = 0; i < n; ++i) {
            // Expand j as long as the condition holds: max <= min * k
            // Use 1LL to prevent integer overflow during multiplication
            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) {
                j++;
            }
            
            // The current valid window is from index i to j-1.
            // Size is (j - 1) - i + 1 = j - i.
            max_kept = max(max_kept, j - i);
        }
        
        // The minimum removals is Total elements - Max elements kept
        return n - max_kept;
    }
};