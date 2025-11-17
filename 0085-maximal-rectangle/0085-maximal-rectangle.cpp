class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            // Build "histogram heights" row by row
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1')
                    height[c] += 1;
                else
                    height[c] = 0;
            }

            // Compute largest rect for this histogram (same as LeetCode 84)
            maxArea = max(maxArea, largestHistogram(height));
        }

        return maxArea;
    }

    int largestHistogram(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();
                long long width = right - left - 1;

                maxArea = max(maxArea, width * height);
            }

            st.push(i);
        }

        return (int)maxArea;
    }
};
