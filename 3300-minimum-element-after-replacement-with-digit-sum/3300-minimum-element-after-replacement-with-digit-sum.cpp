class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int x : nums) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            if (sum < min_val) {
                min_val = sum;
            }
        }
        
        return min_val;
    }
};