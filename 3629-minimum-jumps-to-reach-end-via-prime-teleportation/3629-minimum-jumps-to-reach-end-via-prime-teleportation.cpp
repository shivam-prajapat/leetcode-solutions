class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int mx = 0;
        for (int x : nums) {
            if (x > mx) mx = x;
        }
        
        vector<int> spf(mx + 1);
        for (int i = 1; i <= mx; i++) spf[i] = i;
        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        
        vector<int> mp_head(mx + 1, -1);
        vector<int> mp_to;
        vector<int> mp_next;
        mp_to.reserve(n * 7);
        mp_next.reserve(n * 7);
        int edge_cnt = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                mp_to.push_back(i);
                mp_next.push_back(mp_head[p]);
                mp_head[p] = edge_cnt++;
                
                while (x % p == 0) x /= p;
            }
        }
        
        vector<bool> vis(n, false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front();
                q.pop();
                
                if (u - 1 >= 0 && !vis[u - 1]) {
                    if (u - 1 == n - 1) return ans + 1;
                    vis[u - 1] = true;
                    q.push(u - 1);
                }
                if (u + 1 < n && !vis[u + 1]) {
                    if (u + 1 == n - 1) return ans + 1;
                    vis[u + 1] = true;
                    q.push(u + 1);
                }
                
                int x = nums[u];
                if (x > 1 && spf[x] == x) {
                    for (int e = mp_head[x]; e != -1; e = mp_next[e]) {
                        int v = mp_to[e];
                        if (!vis[v]) {
                            if (v == n - 1) return ans + 1;
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                    mp_head[x] = -1;
                }
            }
            ans++;
        }
        return -1;
    }
};