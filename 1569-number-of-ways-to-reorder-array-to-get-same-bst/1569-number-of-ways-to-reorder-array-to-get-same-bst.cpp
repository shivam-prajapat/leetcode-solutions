class Solution {
    int MOD = 1e9 + 7;
    vector<vector<long long>> table;
    
    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) {
            return 1;
        }
        
        vector<int> left, right;
        for (int i = 1; i < m; ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        
        long long left_ways = dfs(left);
        long long right_ways = dfs(right);
        
        return (((left_ways * right_ways) % MOD) * table[m - 1][left.size()]) % MOD;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1, vector<long long>(n + 1, 0));
        
        for (int i = 0; i <= n; ++i) {
            table[i][0] = 1;
            table[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};