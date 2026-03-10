#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        
        // dp0[i][j] = number of stable arrays with i zeros and j ones ending in 0
        // dp1[i][j] = number of stable arrays with i zeros and j ones ending in 1
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
        
        // Base cases: purely 0s or purely 1s up to the limit
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;
        
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                
                // 1. Calculate combinations ending in 0
                long long val0 = (long long)dp0[i - 1][j] + dp1[i - 1][j];
                if (i > limit) {
                    // Subtract invalid cases where we just formed exactly 'limit + 1' zeros
                    val0 = (val0 - dp1[i - limit - 1][j] + MOD) % MOD;
                }
                dp0[i][j] = val0 % MOD;
                
                // 2. Calculate combinations ending in 1
                long long val1 = (long long)dp0[i][j - 1] + dp1[i][j - 1];
                if (j > limit) {
                    // Subtract invalid cases where we just formed exactly 'limit + 1' ones
                    val1 = (val1 - dp0[i][j - limit - 1] + MOD) % MOD;
                }
                dp1[i][j] = val1 % MOD;
            }
        }
        
        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};