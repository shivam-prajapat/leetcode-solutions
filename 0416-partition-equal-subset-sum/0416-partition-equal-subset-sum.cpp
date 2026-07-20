class Solution {
public:

    bool solve(int i, vector<int>&nums, int sum, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i>=nums.size()) return false;
        

        if(dp[i][sum] != -1) return dp[i][sum];

        bool take = 0;
        if(sum>=nums[i])
        take = solve(i+1,nums, sum-nums[i],dp );
        bool skip = solve(i+1,nums, sum, dp);

        return dp[i][sum] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int i = 0 ;i<nums.size();i++){
            sum+=nums[i];
        }

        if(sum%2 != 0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));

        return solve(0,nums,sum/2,dp);
    }
};