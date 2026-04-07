

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(const vector<int>& nums, int goal) {
        if (goal < 0) return 0; 
        
        int currentSum = 0;
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];
        
            while (currentSum > goal) {
                currentSum -= nums[left];
                left++;
            }
            
            
            count += right - left + 1;
        }
        
        return count;
    }
};