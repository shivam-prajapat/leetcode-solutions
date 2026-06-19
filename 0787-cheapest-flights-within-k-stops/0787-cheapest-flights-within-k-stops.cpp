class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,int>>p;
        p.push({src,0});
        distance[src]=0;

        int steps = 0;

        while(!p.empty() && steps<=k){
            int N = p.size();

            while(N--){
                int node = p.front().first;
                int wt = p.front().second;
                p.pop();

                for(auto it : adj[node]){
                    int adjnode = it.first;
                    int weight = it.second;

                    if(weight+wt < distance[adjnode]){
                        distance[adjnode]=wt+weight;
                        p.push({adjnode,weight+wt});
                    }
                }
            }
            steps++;
        }

        return distance[dst]==INT_MAX?-1 : distance[dst];
    }

};