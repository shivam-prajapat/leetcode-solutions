class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        
        vector<vector<int>> pipes = {
            {0, 0, 0, 0}, 
            {0, 1, 0, 1}, 
            {1, 0, 1, 0},
            {0, 0, 1, 1}, 
            {0, 1, 1, 0},
            {1, 0, 0, 1}, 
            {1, 1, 0, 0} 
        };
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
        
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            
            int currentPipe = grid[x][y];
            
            for (int dir = 0; dir < 4; ++dir) {
           
                if (pipes[currentPipe][dir]) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
             
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        int nextPipe = grid[nx][ny];
                        
                        
                        int oppositeDir = (dir + 2) % 4;
                        
          
                        if (pipes[nextPipe][oppositeDir]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};