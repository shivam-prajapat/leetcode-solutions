class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long F = 0;
        long long n = nums.size();
        
      
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }
        
        long long max_val = F;
        
     
        for (int i = n - 1; i >= 1; i--) {
            F = F + sum - n * (long long)nums[i];
            max_val = max(max_val, F);
        }
        
        return (int)max_val;
    }
};