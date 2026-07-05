class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<int>> dp_score(n, vector<int>(n, -1));
        vector<vector<int>> dp_paths(n, vector<int>(n, 0));
        
        // Start from bottom-right
        dp_score[n - 1][n - 1] = 0;
        dp_paths[n - 1][n - 1] = 1;
        
        // Down, Right, Down-Right (Where we could have come FROM)
        int dr[] = {1, 0, 1};
        int dc[] = {0, 1, 1};
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                // Skip the start cell and obstacles
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) {
                    continue;
                }
                
                int max_prev = -1;
                
                // 1. Find the maximum score from valid predecessors
                for (int i = 0; i < 3; ++i) {
                    int pr = r + dr[i];
                    int pc = c + dc[i];
                    
                    if (pr < n && pc < n && dp_paths[pr][pc] > 0) {
                        max_prev = max(max_prev, dp_score[pr][pc]);
                    }
                }
                
                // 2. If the cell is reachable, update its state
                if (max_prev != -1) {
                    int val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                    dp_score[r][c] = max_prev + val;
                    
                    for (int i = 0; i < 3; ++i) {
                        int pr = r + dr[i];
                        int pc = c + dc[i];
                        
                        // Add paths from all predecessors that yielded the maximum score
                        if (pr < n && pc < n && dp_paths[pr][pc] > 0 && dp_score[pr][pc] == max_prev) {
                            dp_paths[r][c] = (dp_paths[r][c] + dp_paths[pr][pc]) % MOD;
                        }
                    }
                }
            }
        }
        
        // If there is no valid path to 'E', return [0, 0]
        if (dp_paths[0][0] == 0) {
            return {0, 0};
        }
        
        // The score doesn't strictly overflow INT based on constraints (max ~1800), 
        // but we apply the modulo as requested by the problem output requirements.
        return {dp_score[0][0] % MOD, dp_paths[0][0]};
    }
};