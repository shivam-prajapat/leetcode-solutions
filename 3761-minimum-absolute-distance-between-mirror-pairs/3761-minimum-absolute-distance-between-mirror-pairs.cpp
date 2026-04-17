class Solution {
public:
    int reverseDigits(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> previousReversed;
        int minDistance = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (previousReversed.count(nums[i])) {
                int dist = i - previousReversed[nums[i]];
                if (minDistance == -1 || dist < minDistance) {
                    minDistance = dist;
                }
            }
            previousReversed[reverseDigits(nums[i])] = i;
        }
        
        return minDistance;
    }
};