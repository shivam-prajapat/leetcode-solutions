class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();

        // Step 1: Check if conversion is possible
        if (size != m * n) return {};  // empty 2D array

        // Step 2: Create 2D array
        vector<vector<int>> result(m, vector<int>(n));

        // Step 3: Fill the 2D array
        int index = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[index++];
            }
        }

        return result;
    }
};