class Solution {
public:
    int maxArea(vector<int> &heights){
        int n = heights.size();
        int area = 0;
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int nse=i;
                int pse= st.empty() ? -1 : st.top();
                area = max(area,(nse-pse-1)*heights[element]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            area = max(area,(nse-pse-1) * heights[element]);
        }

        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxarea = 0;
        vector<int> height(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            maxarea = max(maxarea,maxArea(height));
        }

        return maxarea;
    }
};