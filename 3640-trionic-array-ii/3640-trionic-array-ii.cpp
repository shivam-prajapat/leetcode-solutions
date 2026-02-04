class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0; // Impossible to form l < p < q < r with fewer than 4 elements

        // Use a sufficiently small number for invalid states
        long long INF = 1e15; 
        
        // State arrays
        // d1[i] -> max sum of strictly INCREASING subarray ending at i (len >= 2)
        // d2[i] -> max sum of INC + DEC subarray ending at i
        // d3[i] -> max sum of INC + DEC + INC subarray ending at i
        vector<long long> d1(n, -INF);
        vector<long long> d2(n, -INF);
        vector<long long> d3(n, -INF);

        long long ans = -INF;

        for (int i = 1; i < n; ++i) {
            // Case A: Current number is larger (Increasing slope)
            if (nums[i] > nums[i - 1]) {
                // 1. Update d1 (Inc)
                // We can either extend the previous d1, or start a new Inc sequence [i-1, i]
                d1[i] = nums[i] + max((long long)nums[i - 1], d1[i - 1]);

                // 2. Update d3 (Inc + Dec + Inc)
                // We are climbing out of the valley.
                // Transition from d2 (the valley bottom) OR extend d3.
                long long best_prev = max(d2[i - 1], d3[i - 1]);
                if (best_prev > -INF) {
                    d3[i] = nums[i] + best_prev;
                }
            }
            // Case B: Current number is smaller (Decreasing slope)
            else if (nums[i] < nums[i - 1]) {
                // Update d2 (Inc + Dec)
                // We are falling from the peak.
                // Transition from d1 (the peak) OR extend d2.
                long long best_prev = max(d1[i - 1], d2[i - 1]);
                if (best_prev > -INF) {
                    d2[i] = nums[i] + best_prev;
                }
            }

            // The answer is the max found in the final stage (d3)
            if (d3[i] > ans) {
                ans = d3[i];
            }
        }

        // If no valid trionic array is found, return 0 (or strictly -INF if problem requires)
        // Based on "Expected -4", we should return the calculated negative value if that's the max.
        return ans;
    }
};