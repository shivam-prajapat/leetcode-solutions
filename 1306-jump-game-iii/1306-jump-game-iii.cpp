class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (arr[u] == 0) return true;
            
            int left = u - arr[u];
            int right = u + arr[u];
            
            if (left >= 0 && !vis[left]) {
                vis[left] = true;
                q.push(left);
            }
            if (right < n && !vis[right]) {
                vis[right] = true;
                q.push(right);
            }
        }
        
        return false;
    }
};