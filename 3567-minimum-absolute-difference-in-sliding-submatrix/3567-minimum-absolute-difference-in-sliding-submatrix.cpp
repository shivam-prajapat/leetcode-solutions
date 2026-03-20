class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result(n - k + 1, vector<int>(m - k + 1, 0));

        for (int i = 0; i + k <= n; i++) {
            for (int j = 0; j + k <= m; j++) {

                vector<int> elements;

                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        elements.push_back(grid[r][c]);
                    }
                }

                if (elements.size() <= 1) {
                    result[i][j] = 0;
                    continue;
                }

                sort(elements.begin(), elements.end());

                int minDiff = INT_MAX;

                for (int t = 1; t < elements.size(); t++) {
                    if (elements[t] != elements[t - 1]) {
                        minDiff = min(minDiff, elements[t] - elements[t - 1]);
                    }
                }

                result[i][j] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }

        return result;
    }
};