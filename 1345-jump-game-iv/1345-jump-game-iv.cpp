class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }
        
        vector<bool> vis(n, false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front();
                q.pop();
                
                if (u == n - 1) return steps;
                
                if (u - 1 >= 0 && !vis[u - 1]) {
                    vis[u - 1] = true;
                    q.push(u - 1);
                }
                if (u + 1 < n && !vis[u + 1]) {
                    vis[u + 1] = true;
                    q.push(u + 1);
                }
                
                if (mp.count(arr[u])) {
                    for (int v : mp[arr[u]]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                    mp.erase(arr[u]);
                }
            }
            steps++;
        }
        
        return steps;
    }
};