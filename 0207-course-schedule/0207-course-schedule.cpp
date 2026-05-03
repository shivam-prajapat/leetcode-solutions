class Solution {
private:
      
    bool DFS(int node,int parent, vector<int>&vis,unordered_map<int,vector<int>>&adj,vector<int>&inRec){
        vis[node]=1;
        inRec[node]=1;

        for(auto &it : adj[node]){

            if(!vis[it] && !DFS(it,node,vis,adj,inRec)){return false;
            } else if(inRec[it]){
                 return false;
            }
           
        }
        inRec[node]=0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>inRec(numCourses,0);

        for(auto &it : prerequisites){
            
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<int>vis(numCourses,0);
        
        for(int i = 0 ;i<numCourses; i++){
            if(!vis[i] && !DFS(i,-1,vis,adj,inRec)){
                return false;
            }
        }
        return true;

        
    }
};