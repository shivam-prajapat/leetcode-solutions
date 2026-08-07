class Solution {
public:

    int solve(vector<int>&nums, int ind, int curSum, int target,vector<vector<int>>&dp, int summ){
        if(ind == nums.size()){
            if(curSum == target){
                return 1;
            }
            return 0;
        }

        if(dp[ind][curSum+summ]!= -1) return dp[ind][curSum + summ];

        int plus = solve(nums, ind+1, curSum + nums[ind], target,dp , summ);
        int minus = solve(nums, ind+1, curSum - nums[ind], target,dp, summ);

        return dp[ind][curSum+summ] =  plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int summ = 0;
        for(int i = 0; i<nums.size(); i++){
            summ+=nums[i];
        }

        vector<vector<int>>dp(nums.size()+1,vector<int>(2*summ+1, -1));

        return solve(nums,0,0,target,dp,summ);
    }
};