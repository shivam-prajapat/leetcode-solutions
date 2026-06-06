class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        vector<int> answer(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            int rightSum = totalSum - leftSum - nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return answer;
    }
};