class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            long long p = 1;
            long long g = 0;
            long long l = 1;
            
            for (int j = i; j < n; ++j) {
                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                
                if (p == l * g) {
                    ans = max(ans, j - i + 1);
                }
                if (p > 25200) {
                    break;
                }
            }
        }
        
        return ans;
    }
};