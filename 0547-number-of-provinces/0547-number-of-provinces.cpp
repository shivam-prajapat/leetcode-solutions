class Solution {
public:
    
    void BFS(int node, unordered_map<int,vector<int>>&adj, vector<int>&vis){

        vis[node]=1;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &it : adj[u]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        vector<int>vis(isConnected.size(),0);
        int count = 0;


        int n = isConnected.size();
        int m = isConnected[0].size();

       for(int i = 0 ;i<n;i++){
        for(int j = 0 ;j<m;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
       }

       for(int i = 0 ;i<n;i++){
        if(!vis[i]){
            BFS(i,adj,vis);
            count++;
        }
       }

       return count;
    }
};