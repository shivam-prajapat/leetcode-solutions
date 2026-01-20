class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            // Count trailing 1s
            int t = 0;
            int x = num;
            while (x & 1) {
                t++;
                x >>= 1;
            }

            if (t == 0) {
                ans.push_back(-1); // even or no trailing 1s
                continue;
            }

            int res = num - (1 << (t - 1));

            if ((res | (res + 1)) == num) {
                ans.push_back(res);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
