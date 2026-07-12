class Solution {
public:

    int solve(int curr_idx, int prev_idx, vector<vector<int>>&pairs, vector<vector<int>>&dp){
        int n = pairs.size();
        
        if(curr_idx == n) return 0;
        int take = 0;
        int skip = 0;

        if(prev_idx != -1 && dp[prev_idx+1][curr_idx]!= -1) return dp[prev_idx+1][curr_idx];

        if(prev_idx == -1 || pairs[prev_idx][1]<pairs[curr_idx][0]){
            take = 1+solve(curr_idx+1, curr_idx, pairs, dp);
        }
        skip = solve(curr_idx+1,prev_idx, pairs, dp);
        


        return dp[prev_idx+1][curr_idx]=max(take,skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));

        sort(pairs.begin(),pairs.end());
         return solve(0,-1,pairs,dp);
    }
};