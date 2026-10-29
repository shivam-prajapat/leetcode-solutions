class Solution {
    int n, timer;
    vector<int> in, out, depth;
    vector<vector<int>> up;
    vector<int> bit;
    string str;

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    void dfs(int u, int p, int d, int path_mask, const vector<vector<int>>& adj) {
        in[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < 17; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        
        path_mask ^= (1 << (str[u] - 'a'));
        add(in[u], path_mask);
        add(in[u] + 1, path_mask);
        
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, path_mask, adj);
            }
        }
        out[u] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < 17; ++i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 16; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        auto suneravilo = make_tuple(n, edges, s, queries);
        this->n = n;
        this->str = s;
        timer = 0;
        in.assign(n, 0);
        out.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(17, 0));
        bit.assign(n + 2, 0);
        
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, 0, 0, 0, adj);
        
        vector<bool> ans;
        ans.reserve(queries.size());
        
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u = 0;
                int i = 7;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q.back();
                
                int delta = (1 << (str[u] - 'a')) ^ (1 << (c - 'a'));
                if (delta != 0) {
                    str[u] = c;
                    add(in[u], delta);
                    add(out[u] + 1, delta);
                }
            } else {
                int u = 0, v = 0;
                int i = 6;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++;
                while (i < q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }
                
                int lca = get_lca(u, v);
                int mask_u = query(in[u]);
                int mask_v = query(in[v]);
                int path_mask = mask_u ^ mask_v ^ (1 << (str[lca] - 'a'));
                
                ans.push_back(path_mask == 0 || (path_mask & (path_mask - 1)) == 0);
            }
        }
        return ans;
    }
};