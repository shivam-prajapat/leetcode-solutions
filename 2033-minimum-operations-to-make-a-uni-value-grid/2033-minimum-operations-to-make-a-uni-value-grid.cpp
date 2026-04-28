class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
      
        nums.reserve(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }
        
      
        for (int val : nums) {
            if (abs(val - nums[0]) % x != 0) {
                return -1;
            }
        }
   
        int k = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + k, nums.end());
        int median = nums[k];
   
        int operations = 0;
        for (int val : nums) {
            operations += abs(val - median) / x;
        }
        
        return operations;
    }
};