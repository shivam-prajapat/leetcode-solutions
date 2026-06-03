class Solution {
public:

    void Dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board){
       int drow[]= {-1,0,1,0};
       int dcol[]={0,1,0,-1};
       int n = board.size();
       int m = board[0].size();

       for(int i = 0 ;i<4 ;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
            vis[nrow][ncol]=1;
            Dfs(nrow,ncol,vis,board);
        }
       }

        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int i = 0 ; i<m ;i++){  //Row
            if(board[0][i]=='O' && vis[0][i]!=1 ){
                vis[0][i]=1;
                Dfs(0,i,vis,board);
            }
            if(board[n-1][i]=='O'&& vis[n-1][i]!=1 ){
                vis[n-1][i]=1;
                Dfs(n-1,i,vis,board);
            }
        }
         for(int j = 0 ; j<n ;j++){ //col
            if(board[j][0]=='O' && vis[j][0]!=1  ){
                vis[j][0]=1;
                Dfs(j,0,vis,board);
            }
            if(board[j][m-1]=='O' && vis[j][m-1]!=1){
                vis[j][m-1]=1;
                Dfs(j,m-1,vis,board);
            }
        }

        for(int i = 0 ;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }

    }
};