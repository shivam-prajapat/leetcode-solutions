class Solution {
public:

    int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
         int n = coins.size();

         if(ind == 0) {
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            return 1e9;
         }

         if(dp[ind][amount] != -1){

            return dp[ind][amount];
         }

         int skip = solve(ind - 1, amount, coins, dp);
         int take = 1e9;

         if(coins[ind]<=amount){
            take = 1+ solve(ind, amount-coins[ind], coins, dp);
         }

         return dp[ind][amount]=min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));

        int ans = solve(coins.size() - 1, amount,coins, dp);

        return (ans>=1e9) ? -1 : ans;

    }
};