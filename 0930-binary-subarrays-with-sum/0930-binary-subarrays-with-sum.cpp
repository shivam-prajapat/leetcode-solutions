#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Exact(goal) = AtMost(goal) - AtMost(goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(const vector<int>& nums, int goal) {
        if (goal < 0) return 0; // A sum cannot be less than 0 since the array only has 0s and 1s
        
        int currentSum = 0;
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];
            
            // Shrink the window from the left if the sum exceeds the goal
            while (currentSum > goal) {
                currentSum -= nums[left];
                left++;
            }
            
            // The number of valid subarrays ending at 'right' is the length of the current window
            count += right - left + 1;
        }
        
        return count;
    }
};