class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> g(n);
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                cnt++;
            }
            g[i] = cnt;
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = g[queries[i][0]] == g[queries[i][1]];
        }

        return ans;
    }
};