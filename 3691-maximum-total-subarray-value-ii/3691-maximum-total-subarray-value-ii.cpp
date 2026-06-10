class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> log_table(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }
        
        int max_log = log_table[n] + 1;
        vector<vector<int>> st_max(n, vector<int>(max_log));
        vector<vector<int>> st_min(n, vector<int>(max_log));
        
        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }
        
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        auto get_val = [&](int L, int R) {
            int j = log_table[R - L + 1];
            int mx = max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
            int mn = min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
            return mx - mn;
        };
        
        struct Element {
            int val;
            int L;
            int R;
            bool operator<(const Element& other) const {
                return val < other.val;
            }
        };
        
        priority_queue<Element> pq;
        for (int L = 0; L < n; L++) {
            pq.push({get_val(L, n - 1), L, n - 1});
        }
        
        long long total_sum = 0;
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            
            total_sum += top.val;
            
            if (top.R - 1 >= top.L) {
                pq.push({get_val(top.L, top.R - 1), top.L, top.R - 1});
            }
        }
        
        return total_sum;
    }
};