class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort by start time (ascending), then by end time (descending)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Descending end time
            }
            return a[0] < b[0];     // Ascending start time
        });
        
        int non_covered_count = 0;
        int max_end = -1;
        
        for (const auto& interval : intervals) {
            // If the current interval extends beyond the max_end seen so far,
            // it is NOT covered.
            if (interval[1] > max_end) {
                non_covered_count++;
                max_end = interval[1];
            }
        }
        
        return non_covered_count;
    }
};