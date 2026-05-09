class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        
        for (int i = 0; i < layers; ++i) {
            int top = i;
            int bottom = m - 1 - i;
            int left = i;
            int right = n - 1 - i;
            
            vector<int> vals;
            for (int j = left; j <= right; ++j) vals.push_back(grid[top][j]);
            for (int j = top + 1; j <= bottom; ++j) vals.push_back(grid[j][right]);
            for (int j = right - 1; j >= left; --j) vals.push_back(grid[bottom][j]);
            for (int j = bottom - 1; j > top; --j) vals.push_back(grid[j][left]);
            
            int sz = vals.size();
            int shift = k % sz;
            auto it = vals.begin() + shift;
            
            for (int j = left; j <= right; ++j) {
                grid[top][j] = *it;
                if (++it == vals.end()) it = vals.begin();
            }
            for (int j = top + 1; j <= bottom; ++j) {
                grid[j][right] = *it;
                if (++it == vals.end()) it = vals.begin();
            }
            for (int j = right - 1; j >= left; --j) {
                grid[bottom][j] = *it;
                if (++it == vals.end()) it = vals.begin();
            }
            for (int j = bottom - 1; j > top; --j) {
                grid[j][left] = *it;
                if (++it == vals.end()) it = vals.begin();
            }
        }
        
        return grid;
    }
};