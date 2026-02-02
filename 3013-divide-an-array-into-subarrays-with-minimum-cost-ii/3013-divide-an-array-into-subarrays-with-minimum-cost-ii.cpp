class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int target = k - 1; // Number of elements we need to pick from the window
        long long current_window_sum = 0;
        multiset<int> left, right;

        // 1. Initialize the first window: indices [1, dist + 1]
        for (int i = 1; i <= dist + 1; ++i) {
            left.insert(nums[i]);
            current_window_sum += nums[i];
        }

        // 2. Initial balance: Move extras from left to right
        while (left.size() > target) {
            auto it = prev(left.end());
            current_window_sum -= *it;
            right.insert(*it);
            left.erase(it);
        }

        long long min_total_cost = current_window_sum;

        // 3. Slide the window
        for (int i = dist + 2; i < n; ++i) {
            // Element leaving: nums[i - dist - 1]
            int out = nums[i - dist - 1];
            auto it = left.find(out);
            
            if (it != left.end()) {
                current_window_sum -= out;
                left.erase(it);
            } else {
                right.erase(right.find(out));
            }

            // Element entering: nums[i]
            // Add to left initially
            left.insert(nums[i]);
            current_window_sum += nums[i];

            // 4. Re-balance to ensure left has exactly 'target' elements
            // If left has more than target, move largest to right
            if (left.size() > target) {
                auto it_max = prev(left.end());
                current_window_sum -= *it_max;
                right.insert(*it_max);
                left.erase(it_max);
            }
            
            // If left has fewer than target, move smallest from right to left
            if (left.size() < target && !right.empty()) {
                auto it_min = right.begin();
                current_window_sum += *it_min;
                left.insert(*it_min);
                right.erase(it_min);
            }
            
            // 5. Final check: Ensure the largest in 'left' is not bigger than the smallest in 'right'
            if (!left.empty() && !right.empty() && *left.rbegin() > *right.begin()) {
                int val_l = *left.rbegin();
                int val_r = *right.begin();
                
                current_window_sum -= val_l;
                current_window_sum += val_r;
                
                left.erase(prev(left.end()));
                right.erase(right.begin());
                
                left.insert(val_r);
                right.insert(val_l);
            }

            min_total_cost = min(min_total_cost, current_window_sum);
        }

        return min_total_cost + (long long)nums[0];
    }
};