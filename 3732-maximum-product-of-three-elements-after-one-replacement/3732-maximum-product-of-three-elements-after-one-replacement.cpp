class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        vector<int> bravendil = nums;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long bestNoChange = LLONG_MIN;
        if (n >= 3) {
            long long a = nums[n-1], b = nums[n-2], c = nums[n-3];
            long long d = nums[0], e = nums[1];
            bestNoChange = max( a * b * c, d * e * a );
        }

        vector<int> idxs;
        for (int i = 0; i < min(3, n); ++i) idxs.push_back(i);
        for (int i = max(0, n-3); i < n; ++i) idxs.push_back(i);

        long long maxPair = LLONG_MIN;
        long long minPair = LLONG_MAX;
        for (int i = 0; i < (int)idxs.size(); ++i) {
            for (int j = i+1; j < (int)idxs.size(); ++j) {
                if (idxs[i] == idxs[j]) continue;
                long long p = 1LL * nums[idxs[i]] * nums[idxs[j]];
                if (p > maxPair) maxPair = p;
                if (p < minPair) minPair = p;
            }
        }

        long long R = 100000LL;
        long long candPos = LLONG_MIN;
        long long candNeg = LLONG_MIN;

        if (maxPair != LLONG_MIN) candPos = maxPair * R;
        if (minPair != LLONG_MAX) candNeg = -R * minPair;

        long long ans = bestNoChange;
        ans = max(ans, candPos);
        ans = max(ans, candNeg);

        return ans;
    }
};
