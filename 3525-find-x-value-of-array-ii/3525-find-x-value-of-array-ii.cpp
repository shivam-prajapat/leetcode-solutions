class SegmentTree {
    struct Node {
        int remain[5] = {0};
        int prod = 1;        
    };
    
    int n, k;
    vector<Node> tree;

   
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k;
      
        for (int i = 0; i < k; ++i) {
            res.remain[i] = left.remain[i];
        }
        
        for (int i = 0; i < k; ++i) {
            res.remain[(left.prod * i) % k] += right.remain[i];
        }
        
        return res;
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int val = nums[start] % k;
            tree[node].prod = val;
            tree[node].remain[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int v = val % k;
            tree[node].prod = v;
            for (int i = 0; i < k; ++i) tree[node].remain[i] = 0;
            tree[node].remain[v] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(int node, int start, int end, int l, int r) {
       
        if (r < start || end < l) {
            return Node(); 
        }
     
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return merge(query(2 * node + 1, start, mid, l, r),
                     query(2 * node + 2, mid + 1, end, l, r));
    }

public:
    SegmentTree(const vector<int>& nums, int k) : n(nums.size()), k(k), tree(4 * nums.size()) {
        build(nums, 0, 0, n - 1);
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    int queryCount(int start, int end, int x) {
        if (start > end) return 0;
        Node res = query(0, 0, n - 1, start, end);
        return res.remain[x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());
        
        int n = nums.size();
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
         
            st.update(idx, val);
            
            
            ans.push_back(st.queryCount(start, n - 1, x));
        }
        
        return ans;
    }
};