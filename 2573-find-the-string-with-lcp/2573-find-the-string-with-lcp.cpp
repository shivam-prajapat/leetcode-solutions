class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string res(n, 0);
        char cur = 'a';

        for (int i = 0; i < n; ++i) {
            if (res[i]) continue;
            if (cur > 'z') return "";
            for (int j = i; j < n; ++j) {
                if (lcp[i][j]) res[j] = cur;
            }
            cur++;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int val = (res[i] == res[j]) ? (i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] + 1 : 1) : 0;
                if (lcp[i][j] != val) return "";
            }
        }

        return res;
    }
};