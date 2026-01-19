class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        
        // 1. Build prefix sum matrix
        vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pre[i][j] = mat[i-1][j-1] 
                          + pre[i-1][j] 
                          + pre[i][j-1] 
                          - pre[i-1][j-1];
            }
        }

        // Helper to check if a square of size k is possible
        auto possible = [&](int k) {
            for(int i = k; i <= n; i++){
                for(int j = k; j <= m; j++){
                    int sum = pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k];
                    if(sum <= threshold) return true;
                }
            }
            return false;
        };

        // 2. Binary Search on side length
        int low = 0, high = min(n, m), ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(mid)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
