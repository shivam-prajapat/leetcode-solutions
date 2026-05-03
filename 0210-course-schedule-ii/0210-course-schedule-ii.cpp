class Solution {
public:

bool hasCycle;  


    void DFS(int node, unordered_map<int,vector<int>>&adj, vector<int>&vis, stack<int>&st,vector<int>&inRecursion ) {

        vis[node]=1;
        inRecursion[node]=1;
        for(auto &it : adj[node]){
            if(inRecursion[it]){
                hasCycle = true;
                return;
            }

            if(!vis[it]){
                DFS(it,adj,vis,st,inRecursion);
            }
        }
        st.push(node);
        inRecursion[node]=0;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>vis(numCourses,0);
        vector<int>res;
        stack<int>st;
        vector<int>inRecursion(numCourses,0);

        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        for(int i = 0 ;i<numCourses;i++){
            if(!vis[i]){
                DFS(i,adj,vis,st,inRecursion);
            }
        }

        if(hasCycle){
            return {};
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        return res;




    }
};