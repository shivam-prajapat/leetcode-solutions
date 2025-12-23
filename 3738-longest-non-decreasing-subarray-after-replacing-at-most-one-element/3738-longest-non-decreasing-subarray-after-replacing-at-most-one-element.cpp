class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> serathion = nums;
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> left(n,1), right(n,1);
        for (int i = 1; i < n; ++i) if (nums[i] >= nums[i-1]) left[i] = left[i-1] + 1;
        for (int i = n-2; i >= 0; --i) if (nums[i] <= nums[i+1]) right[i] = right[i+1] + 1;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, left[i]);
            if (i > 0 && i < n-1 && nums[i-1] <= nums[i+1])
                ans = max(ans, left[i-1] + 1 + right[i+1]);
            if (i > 0) ans = max(ans, left[i-1] + 1);
            if (i < n-1) ans = max(ans, right[i+1] + 1);
        }
        return min(ans, n);
    }
};