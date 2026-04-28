class Solution {
private:
    void dfs ( int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int inicolor, int color, int delRow[], int delCol[]){

        ans[row][col] = color;

        int n = image.size();
        int m = image[0].size();

        for(int i = 0 ; i<4 ; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==inicolor){
               dfs (nrow, ncol, image, ans , inicolor,color,delRow, delCol);
            }
        }
    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        vector<vector<int>> ans = image;

        dfs (sr, sc, image, ans , inicolor,color,delRow, delCol);

        return ans;
    }
};