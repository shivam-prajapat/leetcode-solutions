class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;

        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));

        result[0][0]=0;
        pq.push({0,{0,0}});

        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();

            for(int i = 0 ;i<8 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                int dist = 1;

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==0 && d+dist<result[nrow][ncol]){
                    result[nrow][ncol]=d+dist;
                    pq.push({d+dist,{nrow,ncol}});
                }
            }

        }

        if(result[n-1][m-1]==INT_MAX){
            return -1;
        }

        return result[n-1][m-1]+1;

    }
};