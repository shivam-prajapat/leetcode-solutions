class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 1) return false;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        
        return nums[n] == n;
    }
};