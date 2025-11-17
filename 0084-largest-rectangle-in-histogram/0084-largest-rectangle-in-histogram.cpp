class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;      // will store indices
        long long maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // virtual height = 0 when i == n (forces clearing stack)
            int h = (i == n ? 0 : heights[i]);

            // Pop while current height is smaller than stack top height
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
