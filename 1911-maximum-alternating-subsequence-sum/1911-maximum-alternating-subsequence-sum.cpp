class Solution {
public:

    long long solve(int i,bool flag, vector<int>& nums, vector<vector<long long>>&dp){

        if(i==nums.size()){
            return 0;
        }

        if(dp[i][flag]!= -1){
            return dp[i][flag];
        }

        long long skip = solve(i+1,flag, nums, dp);

        long long val = nums[i];

        if(flag == false){
            val = -val;
        }

        long long take = val + solve(i+1,!flag, nums,dp);

        return dp[i][flag] = max(take, skip);


    }

    long long maxAlternatingSum(vector<int>& nums) {

         int n = nums.size();

         vector<vector<long long>>dp(nums.size()+1,vector<long long>(2,-1));
         if(n==0) return 0;
         if(n==1)return nums[0];
         if(n==2)return abs(nums[0]-nums[1]);

        return solve(0,true,nums,dp);
    }
};