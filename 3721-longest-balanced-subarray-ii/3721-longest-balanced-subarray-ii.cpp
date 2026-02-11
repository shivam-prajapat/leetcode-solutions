class Solution {
    struct Node { 
        int mn; 
        int mx; // Added max to track range
        int lazy; 
    };
    
    vector<Node> seg;
    int n;

    void build(int id, int l, int r) {
        seg[id].lazy = 0;
        if (l == r) { 
            seg[id].mn = 0; 
            seg[id].mx = 0; 
            return; 
        }
        int m = (l + r) >> 1;
        build(id<<1, l, m);
        build(id<<1|1, m+1, r);
        seg[id].mn = min(seg[id<<1].mn, seg[id<<1|1].mn);
        seg[id].mx = max(seg[id<<1].mx, seg[id<<1|1].mx);
    }

    void apply(int id, int v) {
        seg[id].mn += v;
        seg[id].mx += v; // Apply to max as well
        seg[id].lazy += v;
    }

    void push(int id) {
        if (seg[id].lazy != 0) {
            apply(id<<1, seg[id].lazy);
            apply(id<<1|1, seg[id].lazy);
            seg[id].lazy = 0;
        }
    }

    void update(int id, int l, int r, int ql, int qr, int val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) { apply(id, val); return; }
        push(id);
        int m = (l + r) >> 1;
        update(id<<1, l, m, ql, qr, val);
        update(id<<1|1, m+1, r, ql, qr, val);
        seg[id].mn = min(seg[id<<1].mn, seg[id<<1|1].mn);
        seg[id].mx = max(seg[id<<1].mx, seg[id<<1|1].mx);
    }

    // Find the leftmost index where value is 0
    int findFirstZero(int id, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return -1;
        
        // Optimization: If 0 is not in the range [min, max], it doesn't exist here
        if (seg[id].mn > 0 || seg[id].mx < 0) return -1;
        
        if (l == r) return l; // Found it

        push(id);
        int m = (l + r) >> 1;
        
        // Try left child first to maximize subarray length (minimize L)
        int res = findFirstZero(id<<1, l, m, ql, qr);
        if (res != -1) return res;
        
        return findFirstZero(id<<1|1, m+1, r, ql, qr);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;
        seg.assign(4 * (n + 1), {0, 0, 0});
        build(1, 1, n);

        unordered_map<long long, int> last;
        int ans = 0;
        
        for (int r = 1; r <= n; ++r) {
            long long x = nums[r-1];
            int prev = last.count(x) ? last[x] : 0;
            
            // Logic: update contribution of x for all subarrays starting after its last occurrence
            int weight = (x % 2 == 0) ? 1 : -1;
            update(1, 1, n, prev + 1, r, weight);
            
            last[x] = r;
            
            // Find the smallest L such that DistinctEvens - DistinctOdds = 0
            int l_idx = findFirstZero(1, 1, n, 1, r);
            
            if (l_idx != -1) {
                ans = max(ans, r - l_idx + 1);
            }
        }
        return ans;
    }
};