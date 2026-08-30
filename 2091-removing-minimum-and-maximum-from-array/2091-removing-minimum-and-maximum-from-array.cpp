class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }
        
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);
        
        int option1 = j + 1;             // Delete both from the front
        int option2 = n - i;             // Delete both from the back
        int option3 = (i + 1) + (n - j); // Delete i from front, j from back
        
        return min({option1, option2, option3});
    }
};