class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        
        result[0][0]=0;
        pq.push({0,{0,0}});

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();

            for(int i = 0 ;i<4; i++){
                int nrow = row+drow[i];
                int ncol = col + dcol[i];
               
                
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                    
                    int newEffort = max(dist,abs(heights[row][col]-heights[nrow][ncol]));

                    if(newEffort < result[nrow][ncol]){
                    result[nrow][ncol]=newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                    }
                    }

                }
            }
        
     
        return result[n-1][m-1];


    }
};