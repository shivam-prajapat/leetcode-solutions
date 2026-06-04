class Solution {
public:

    void DFS(int row,int col, vector<vector<int>>&grid, vector<vector<int>>&vis){
        int n = grid.size();
        int m = grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i = 0 ;i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 &&  !vis[nrow][ncol]){

                vis[nrow][ncol]=1;
                DFS(nrow,ncol,grid,vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        //Row

        for(int i = 0 ;i<n; i++){
            if(grid[i][0]==1 && vis[i][0]!=1){
                vis[i][0]=1;
                DFS(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]!=1){
                vis[i][m-1]=1;
                DFS(i,m-1,grid,vis);
            }
        }
        //col

        for(int j = 0 ;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]!=1){
                vis[0][j]=1;
                DFS(0,j,grid,vis);
            }

            if(grid[n-1][j]==1 && !vis[n-1][j]){
                vis[n-1][j]=1;
                DFS(n-1,j,grid,vis);
            }
        }
        int count = 0 ;

        for(int i = 0 ;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }

        return count;
    }

};