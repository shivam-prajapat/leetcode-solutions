class Solution {
public:

    bool dfs(int u, int v, vector<int>&vis, unordered_map<int,vector<int>>&adj ){

        vis[u]=1;

        if(u==v){
            return true;
        }

        for(int &ngbr : adj[u]){
            if(vis[ngbr]) continue;

            if(dfs(ngbr,v,vis,adj)){
                return true;
            }
        }
        return false;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
   

        for(int i = 0 ;i<n ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
              vector<int>vis(n+1,0);

            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(u,v,vis,adj) ){
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};



    }
};