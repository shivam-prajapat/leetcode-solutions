class Solution {
public:

    int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>result(n,LLONG_MAX);
        vector<int>path_count(n,0);

        result[0]=0;
        path_count[0]=1;

        pq.push({0,0});

        while(!pq.empty()){
            int node = pq.top().second;
            long long weight = pq.top().first;

            pq.pop();
            for(auto temp : adj[node]){
                int ngbhr = temp.first;
                int wt = temp.second;

                if(weight + wt < result[ngbhr]){
                    result[ngbhr]=weight+wt;
                    pq.push({result[ngbhr],ngbhr});
                    path_count[ngbhr]=path_count[node];
                }else if(weight + wt == result[ngbhr]){
                    path_count[ngbhr]=(path_count[ngbhr]+path_count[node])%M;
                }
            }
        }

        return path_count[n-1];
    }
};