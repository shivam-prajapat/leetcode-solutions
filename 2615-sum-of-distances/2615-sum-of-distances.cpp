
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
    
        unordered_map<int, vector<long long>> indices;
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }
     
        for (auto& [val, group] : indices) {
            long long k = group.size();
            long long total_sum = 0;
        
            for (long long idx : group) {
                total_sum += idx;
            }
            
            long long prefix_sum = 0;
   
            for (int j = 0; j < k; ++j) {
                long long curr_idx = group[j];
                long long suffix_sum = total_sum - prefix_sum - curr_idx;
          
                long long left_dist = j * curr_idx - prefix_sum;
                
         
                long long right_dist = suffix_sum - (k - 1 - j) * curr_idx;
                
                ans[curr_idx] = left_dist + right_dist;
            
                prefix_sum += curr_idx;
            }
        }
        
        return ans;
    }
};