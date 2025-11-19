class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;

        for (int x : nums) {
            if (x == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }

        return maxCount;
    }
};
