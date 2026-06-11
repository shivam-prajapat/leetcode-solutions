class Solution {
public:

    bool DFS(int node, int parent, vector<int>&vis,vector<int>&inRec, vector<vector<int>>&adj){

        vis[node]=1;
        inRec[node]=1;

        for(auto &it : adj[node]){
          if(!vis[it] && !DFS(it,node,vis,inRec,adj)){
            return false;
          }
          else if(inRec[it]){
            return false;
          }
        }
        inRec[node]=0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>inRec(numCourses,0);

        vector<vector<int>>adj(numCourses);

        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }


        for(int i = 0 ; i<numCourses;i++){
            if(!vis[i]){
                if(!DFS(i,-1,vis,inRec,adj)){
                    return false ;
                };
            }
        }
        return true;
    }
};