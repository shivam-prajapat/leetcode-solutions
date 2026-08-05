class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        vector<bool> suspicious(n, false);
        vector<int> q;
        q.push_back(k);
        suspicious[k] = true;
        
        int head = 0;
        while (head < q.size()) {
            int u = q[head++];
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push_back(v);
                }
            }
        }
        
        bool can_remove = true;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                for (int v : adj[i]) {
                    if (suspicious[v]) {
                        can_remove = false;
                        break;
                    }
                }
                if (!can_remove) break;
            }
        }
        
        vector<int> ans;
        if (can_remove) {
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {
                    ans.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};