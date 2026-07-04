
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        int min_score = 1e9;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                min_score = min(min_score, weight);
                
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        return min_score;
    }
};