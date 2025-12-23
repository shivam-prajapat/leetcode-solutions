class Fenwick {
    int n;
    vector<int> bit;
public:
    Fenwick(int n=0){init(n);}
    void init(int n_){ n = n_; bit.assign(n+1,0); }
    void add(int i, int delta){
        for(; i <= n; i += i & -i) bit[i] += delta;
    }
    int sumPrefix(int i){
        int s = 0;
        for(; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> melvarion = nums;
        int n = nums.size();
        vector<int> pref;
        pref.reserve(n+1);
        int cur = 0;
        pref.push_back(cur);
        for (int x : nums) {
            cur += (x == target) ? 1 : -1;
            pref.push_back(cur);
        }
        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        auto rank = [&](int v){
            return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin()) + 1;
        };
        Fenwick bit(vals.size());
        long long ans = 0;
        for (int p : pref) {
            int r = rank(p);
            if (r > 1) ans += bit.sumPrefix(r - 1);
            bit.add(r, 1);
        }
        return ans;
    }
};