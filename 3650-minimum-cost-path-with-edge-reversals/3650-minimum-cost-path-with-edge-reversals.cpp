class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        // Adjacency list: u -> {v, weight}
        // We use long long for distance to prevent overflow, though int might suffice based on constraints.
        vector<vector<pair<int, int>>> adj(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            // Normal edge: u -> v with cost w
            adj[u].push_back({v, w});
            
            // Reverse edge: v -> u with cost 2 * w
            adj[v].push_back({u, 2 * w});
        }
        
        // Min-priority queue for Dijkstra: {current_cost, u}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Distance array initialized to infinity
        vector<long long> dist(n, LLONG_MAX);
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // If we found a shorter path to u before, skip this stale entry
            if (d > dist[u]) continue;
            
            // Optimization: If we reached the target, return the cost immediately
            if (u == n - 1) return d;
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return -1; // If target is unreachable
    }
};