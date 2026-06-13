class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;

       
        vector<int>indeg(numCourses,0);
        vector<int>res;

        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        for(int i = 0 ;i<numCourses;i++){
            for(auto &it : adj[i]){
                indeg[it]++;
            }
        }

        queue<int>q;
        for(int i = 0 ;i<numCourses; i++){
            if(indeg[i]==0){
                    q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto &it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }

        }
        if(numCourses != res.size()){
            return {};
        }

        return res;
            
        }
    
};