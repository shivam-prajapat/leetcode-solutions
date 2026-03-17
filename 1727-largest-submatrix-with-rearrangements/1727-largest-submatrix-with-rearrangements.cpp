#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Build height matrix
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int ans = 0;

        // Step 2: Process each row
        for (int i = 0; i < n; i++) {
            vector<int> row = matrix[i];

            // Sort in descending order
            sort(row.begin(), row.end(), greater<int>());

            // Step 3: Calculate max area
            for (int j = 0; j < m; j++) {
                int height = row[j];
                int width = j + 1;
                ans = max(ans, height * width);
            }
        }

        return ans;
    }
};