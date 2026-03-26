class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        unordered_map<long long, int> all;
        for (auto &row : grid) {
            for (int x : row) {
                total += x;
                all[x]++;
            }
        }

        unordered_map<long long, int> top, bottom = all;
        long long topSum = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                long long v = grid[i][j];
                top[v]++;
                if (--bottom[v] == 0) bottom.erase(v);
                topSum += v;
            }

            long long bottomSum = total - topSum;

            if (topSum == bottomSum) return true;

            long long diff = llabs(topSum - bottomSum);

            if (topSum > bottomSum) {
                if (can(top, grid, 0, 0, i, n - 1, diff)) return true;
            } else {
                if (can(bottom, grid, i + 1, 0, m - 1, n - 1, diff)) return true;
            }
        }

        unordered_map<long long, int> left, right = all;
        long long leftSum = 0;

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                long long v = grid[i][j];
                left[v]++;
                if (--right[v] == 0) right.erase(v);
                leftSum += v;
            }

            long long rightSum = total - leftSum;

            if (leftSum == rightSum) return true;

            long long diff = llabs(leftSum - rightSum);

            if (leftSum > rightSum) {
                if (can(left, grid, 0, 0, m - 1, j, diff)) return true;
            } else {
                if (can(right, grid, 0, j + 1, m - 1, n - 1, diff)) return true;
            }
        }

        return false;
    }

private:
    bool can(const unordered_map<long long, int>& freq,
             const vector<vector<int>>& grid,
             int r1, int c1, int r2, int c2,
             long long diff) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows == 1 && cols == 1) return false;
        if (rows == 1) return grid[r1][c1] == diff || grid[r1][c2] == diff;
        if (cols == 1) return grid[r1][c1] == diff || grid[r2][c1] == diff;

        return freq.find(diff) != freq.end();
    }
};