class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // The first element nums[0] is always the cost of the first subarray.
        // We need to find two other starting positions (i and j) in the remaining
        // elements (index 1 to n-1) that have the smallest values to minimize the total sum.
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        // Iterate starting from index 1 to find the two smallest elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        return nums[0] + min1 + min2;
    }
};