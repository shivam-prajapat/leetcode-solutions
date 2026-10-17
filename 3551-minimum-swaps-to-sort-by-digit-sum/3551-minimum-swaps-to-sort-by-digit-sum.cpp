class Solution {
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        
        sort(arr.begin(), arr.end());
        
        int swaps = 0;
        vector<bool> vis(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (vis[i] || arr[i].second == i) {
                continue;
            }
            
            int cycle_len = 0;
            int j = i;
            
            while (!vis[j]) {
                vis[j] = true;
                j = arr[j].second;
                cycle_len++;
            }
            
            swaps += cycle_len - 1;
        }
        
        return swaps;
    }
};