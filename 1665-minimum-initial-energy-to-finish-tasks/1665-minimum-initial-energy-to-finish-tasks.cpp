class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int ans = 0;
        int current = 0;
        
        for (const auto& task : tasks) {
            if (current < task[1]) {
                ans += task[1] - current;
                current = task[1];
            }
            current -= task[0];
        }
        
        return ans;
    }
};