class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        if(m==0 || n== 0 || grid[n-1][m-1]!=0 || grid[0][0]!=0){
            return -1;
        }

        if(n==1 && m == 1){
            return 1;
        }

        int count = 0;
        queue<pair<int,pair<int,int>>>q;

        q.push({1,{0,0}});
        vis[0][0]=1;

        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            for(int i = 0 ;i<8;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]!=1 && grid[nrow][ncol]==0){
                    if(nrow == n-1 && ncol == m-1 ){
                        return dis+1;
                    }
                    vis[nrow][ncol]=1;
                    q.push({dis+1,{nrow,ncol}});
                    
                }
               
            }

            


        }
        return -1;


    }
};