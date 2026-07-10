class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {nums[i], i};
        }
        sort(A.begin(), A.end());
        
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[A[i].second] = i;
        }
        
        int K = 18;
        vector<vector<int>> upL(K, vector<int>(n));
        vector<vector<int>> upR(K, vector<int>(n));
        
        for (int i = 0, j = 0; i < n; ++i) {
            while ((long long)A[i].first - A[j].first > maxDiff) {
                j++;
            }
            upL[0][i] = j;
        }
        
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            while ((long long)A[j].first - A[i].first > maxDiff) {
                j--;
            }
            upR[0][i] = j;
        }
        
        for (int k = 1; k < K; ++k) {
            for (int i = 0; i < n; ++i) {
                upL[k][i] = upL[k - 1][upL[k - 1][i]];
                upR[k][i] = upR[k - 1][upR[k - 1][i]];
            }
        }
        
        vector<int> ans(queries.size());
        for (int q = 0; q < queries.size(); ++q) {
            int u = queries[q][0];
            int v = queries[q][1];
            
            if (u == v) {
                ans[q] = 0;
                continue;
            }
            
            int S = pos[u];
            int T = pos[v];
            
            if (T < upL[K - 1][S] || T > upR[K - 1][S]) {
                ans[q] = -1;
                continue;
            }
            
            int curL = S;
            int curR = S;
            int d = 0;
            
            for (int k = K - 1; k >= 0; --k) {
                int nextL = upL[k][curL];
                int nextR = upR[k][curR];
                
                if (T < nextL || T > nextR) {
                    curL = nextL;
                    curR = nextR;
                    d += (1 << k);
                }
            }
            
            ans[q] = d + 1;
        }
        
        return ans;
    }
};