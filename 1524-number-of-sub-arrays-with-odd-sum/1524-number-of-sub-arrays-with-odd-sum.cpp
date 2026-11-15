class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int even_count = 1;
        int odd_count = 0;
        int parity = 0;
        int ans = 0;
        
        for (int num : arr) {
            parity ^= (num & 1);
            if (parity == 1) {
                ans += even_count;
                if (ans >= MOD) ans -= MOD;
                odd_count++;
            } else {
                ans += odd_count;
                if (ans >= MOD) ans -= MOD;
                even_count++;
            }
        }
        
        return ans;
    }
};