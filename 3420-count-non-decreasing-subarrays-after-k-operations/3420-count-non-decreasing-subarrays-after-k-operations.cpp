class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        deque<pair<int, int>> dq;
        int r = n - 1;
        
        for (int l = n - 1; l >= 0; --l) {
            int cnt = 1;
            while (!dq.empty() && dq.front().first <= nums[l]) {
                cost += (long long)(nums[l] - dq.front().first) * dq.front().second;
                cnt += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], cnt});
            
            while (cost > k) {
                cost -= dq.back().first - nums[r];
                dq.back().second--;
                if (dq.back().second == 0) {
                    dq.pop_back();
                }
                r--;
            }
            
            ans += r - l + 1;
        }
        
        return ans;
    }
};