class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());
        int ans = 0;
        
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool possible = true;
            for (int i = 0; i < n / k; ++i) {
                int drops = 0;
                int drop_idx = -1;
                int offset = i * k;
                
                for (int j = 0; j < k - 1; ++j) {
                    if (nums[offset + j] > nums[offset + j + 1]) {
                        drops++;
                        drop_idx = j;
                    }
                }
                if (nums[offset + k - 1] > nums[offset]) {
                    drops++;
                    drop_idx = k - 1;
                }
                
                if (drops > 1) {
                    possible = false;
                    break;
                }
                
                int start_idx = (drops == 0) ? 0 : (drop_idx + 1) % k;
                
                for (int j = 0; j < k; ++j) {
                    if (nums[offset + (start_idx + j) % k] != s[offset + j]) {
                        possible = false;
                        break;
                    }
                }
                
                if (!possible) break;
            }
            if (possible) {
                ans += k;
            }
        }
        
        return ans;
    }
};