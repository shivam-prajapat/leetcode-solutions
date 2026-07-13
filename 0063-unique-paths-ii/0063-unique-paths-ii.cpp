class Solution {
public:

    int solve(int row, int col, vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){

        if(row>=0 && col>=0 && obstacleGrid[row][col]==1){
            return 0;
        }

        if(row == 0 && col == 0){
            return 1;
        }


        if(row<0 || col<0){
            return 0;
        }
        


        if(dp[row][col]!= -1 ){
            return dp[row][col];
        }

        int left = solve(row, col -1, dp, obstacleGrid);
        int up = solve(row -1 , col, dp, obstacleGrid);
        return dp[row][col]= left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();


        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1,m-1,dp,obstacleGrid);
    }
};