class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0;
        int equalCount = 0;
        
        for (int num : nums) {
            if (num < target) {
                lessCount++;
            } else if (num == target) {
                equalCount++;
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < equalCount; ++i) {
            ans.push_back(lessCount + i);
        }
        
        return ans;
    }
};