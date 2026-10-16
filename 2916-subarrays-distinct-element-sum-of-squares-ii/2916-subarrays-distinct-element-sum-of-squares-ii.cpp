class Solution {
    struct Node {
        long long sumSq;
        long long sum;
        long long lazy;
    };
    
    vector<Node> tree;
    int MOD = 1e9 + 7;
    
    void push_down(int v, int tl, int tr) {
        if (tree[v].lazy != 0) {
            int tm = tl + (tr - tl) / 2;
            long long val = tree[v].lazy;
            long long lenLeft = tm - tl + 1;
            long long lenRight = tr - tm;
            
            int left = v * 2;
            tree[left].sumSq = (tree[left].sumSq + 2 * val * tree[left].sum + val * val % MOD * lenLeft) % MOD;
            tree[left].sum = (tree[left].sum + val * lenLeft) % MOD;
            tree[left].lazy = (tree[left].lazy + val) % MOD;
            
            int right = v * 2 + 1;
            tree[right].sumSq = (tree[right].sumSq + 2 * val * tree[right].sum + val * val % MOD * lenRight) % MOD;
            tree[right].sum = (tree[right].sum + val * lenRight) % MOD;
            tree[right].lazy = (tree[right].lazy + val) % MOD;
            
            tree[v].lazy = 0;
        }
    }
    
    void update(int v, int tl, int tr, int l, int r, long long val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            long long len = tr - tl + 1;
            tree[v].sumSq = (tree[v].sumSq + 2 * val * tree[v].sum + val * val % MOD * len) % MOD;
            tree[v].sum = (tree[v].sum + val * len) % MOD;
            tree[v].lazy = (tree[v].lazy + val) % MOD;
            return;
        }
        push_down(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
        tree[v].sumSq = (tree[v * 2].sumSq + tree[v * 2 + 1].sumSq) % MOD;
        tree[v].sum = (tree[v * 2].sum + tree[v * 2 + 1].sum) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 1, {0, 0, 0});
        unordered_map<int, int> last;
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;
            update(1, 0, n - 1, prev + 1, i, 1);
            ans = (ans + tree[1].sumSq) % MOD;
            last[nums[i]] = i;
        }
        
        return ans;
    }
};