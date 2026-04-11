class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        
        vector<vector<int>> indices(n + 1);
        
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }
        
        int min_dist = -1;
        
        for (int i = 1; i <= n; ++i) {
            const auto& pos = indices[i];
            int m = pos.size();
            
            
            for (int h = 0; h < m - 2; ++h) {
               
                int dist = (pos[h + 2] - pos[h]) * 2;
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
        
        return min_dist;
    }
};