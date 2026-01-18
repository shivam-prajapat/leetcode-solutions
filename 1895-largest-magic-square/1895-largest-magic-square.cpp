class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Prefix sums for rows, columns, diagonals
        vector<vector<int>> row(m, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n, 0));
        vector<vector<int>> diag1(m+1, vector<int>(n+1, 0)); // main diagonal
        vector<vector<int>> diag2(m+1, vector<int>(n+2, 0)); // anti-diagonal

        // Build prefix sums
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i][j+1] = row[i][j] + grid[i][j];
                col[i+1][j] = col[i][j] + grid[i][j];
                diag1[i+1][j+1] = diag1[i][j] + grid[i][j];
                diag2[i+1][j] = diag2[i][j+1] + grid[i][j];
            }
        }

        int ans = 1; // Any single cell is trivially a magic square

        // Try all square sizes k >= 2
        for(int k = 2; k <= min(m, n); k++){
            for(int i = 0; i + k <= m; i++){
                for(int j = 0; j + k <= n; j++){
                    
                    int target = row[i][j+k] - row[i][j]; // first row sum
                    bool ok = true;

                    // Check rows
                    for(int r = i; r < i+k && ok; r++){
                        if(row[r][j+k] - row[r][j] != target)
                            ok = false;
                    }

                    // Check columns
                    for(int c = j; c < j+k && ok; c++){
                        if(col[i+k][c] - col[i][c] != target)
                            ok = false;
                    }

                    // Check diagonals
                    int d1 = diag1[i+k][j+k] - diag1[i][j];
                    int d2 = diag2[i+k][j] - diag2[i][j+k];
                    if(d1 != target || d2 != target)
                        ok = false;

                    if(ok) ans = k;
                }
            }
        }

        return ans;
    }
};
