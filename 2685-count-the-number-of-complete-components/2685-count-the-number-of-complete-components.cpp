class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(n, false);
        int complete_count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int nodes = 0;
                int degrees = 0;
                queue<int> q;
                
                q.push(i);
                vis[i] = true;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    nodes++;
                    degrees += adj[u].size();
                    
                    for (int v : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
                
                if (degrees == nodes * (nodes - 1)) {
                    complete_count++;
                }
            }
        }
        
        return complete_count;
    }
};