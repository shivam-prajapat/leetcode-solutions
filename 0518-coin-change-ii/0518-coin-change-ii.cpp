class Solution {
public:

    int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
         int n = coins.size();
         if (ind == 0)
            return (amount % coins[0] == 0);

         if (dp[ind][amount] != -1)
            return dp[ind][amount];

          int skip = solve(ind - 1, amount, coins,dp);

         int take = 0;
         if (coins[ind] <= amount)
            take = solve(ind, amount - coins[ind],coins,dp);

         return dp[ind][amount] = take + skip;


    }
    int change(int amount, vector<int>& coins) {

        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));

        
        int ans = solve(coins.size() - 1, amount,coins, dp);

        return ans;


    }
};