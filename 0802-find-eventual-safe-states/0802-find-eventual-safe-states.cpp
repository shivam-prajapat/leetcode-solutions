class Solution {
public:

    bool DFS(int node,vector<int>&vis,vector<int>&inRec,vector<vector<int>>&graph){

        vis[node]=1;
        inRec[node]=1;

        for(auto it : graph[node]){
            if(!vis[it] && DFS(it,vis,inRec,graph)){
                return true;
            }
            else if(inRec[it]){
                return true;
            }
        }
        inRec[node]=0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
        vector<int>vis(graph.size(),0);
        vector<int>inRec(graph.size(),0);

        vector<int>res;



        for(int i = 0 ;i<graph.size();i++){
            if(!vis[i]){
                DFS(i,vis,inRec,graph);
                
            }
        }

        for(int i  = 0 ;i<inRec.size();i++){
            if(inRec[i]!=1){
                res.push_back(i);
            }
        }


        sort(res.begin(),res.end());
        return res;
    }
};