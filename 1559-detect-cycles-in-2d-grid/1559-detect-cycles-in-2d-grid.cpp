
class Solution {
public:
    int m, n;

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int parentR, int parentC, char val) {
        visited[r][c] = true;

  
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

          
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == val) {
                if (!visited[nr][nc]) {
                  
                    if (dfs(grid, visited, nr, nc, r, c, val)) {
                        return true;
                    }
                } else if (nr != parentR || nc != parentC) {
                  
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

      
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
               
                if (!visited[i][j]) {
                   
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};