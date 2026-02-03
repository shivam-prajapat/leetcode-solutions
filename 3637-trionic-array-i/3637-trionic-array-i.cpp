class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        // Iterate through all possible pivot points p and q
        // Constraint: 0 < p < q < n - 1
        for (int p = 1; p <= n - 3; ++p) {
            for (int q = p + 1; q <= n - 2; ++q) {
                
                // 1. Check increasing part: nums[0...p]
                bool isInc1 = true;
                for (int i = 0; i < p; ++i) {
                    if (nums[i] >= nums[i + 1]) {
                        isInc1 = false;
                        break;
                    }
                }
                if (!isInc1) continue;

                // 2. Check decreasing part: nums[p...q]
                bool isDec = true;
                for (int i = p; i < q; ++i) {
                    if (nums[i] <= nums[i + 1]) {
                        isDec = false;
                        break;
                    }
                }
                if (!isDec) continue;

                // 3. Check increasing part: nums[q...n-1]
                bool isInc2 = true;
                for (int i = q; i < n - 1; ++i) {
                    if (nums[i] >= nums[i + 1]) {
                        isInc2 = false;
                        break;
                    }
                }
                
                if (isInc2) return true;
            }
        }

        return false;
    }
};