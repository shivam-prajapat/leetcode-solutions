class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(points.size(),0);

        unordered_map<int,vector<pair<int,int>>>adj;
        int sum = 0 ;

        for(int i = 0 ;i<points.size();i++){
            for(int j = i+1 ;j<points.size();j++){
                int dist = abs(points[i][0] - points[j][0])+abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        pq.push({0,0});

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node]){
                continue;
            }
            vis[node]=1;
            sum +=weight;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(vis[adjNode]==0){
                    pq.push({wt,adjNode});
                }
            }
        }
        return sum;

    }
};