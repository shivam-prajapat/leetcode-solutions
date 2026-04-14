class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
       
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

       
        vector<int> flat_factories;
        for (const auto& f : factory) {
            int pos = f[0];
            
            int limit = min((int)robot.size(), f[1]); 
            for (int i = 0; i < limit; ++i) {
                flat_factories.push_back(pos);
            }
        }

        int n = robot.size();
        int m = flat_factories.size();

      
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

       
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }

    
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                
                dp[i][j] = dp[i][j - 1]; 

              
                if (dp[i - 1][j - 1] != 1e18) {
                    long long dist = abs((long long)robot[i - 1] - flat_factories[j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist);
                }
            }
        }

        
        return dp[n][m];
    }
};