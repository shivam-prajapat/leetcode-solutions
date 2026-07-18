class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int gcd = __gcd(mini, maxi);
        return gcd;

    }
};