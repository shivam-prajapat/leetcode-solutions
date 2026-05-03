class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>vis(numCourses,0);
        int count = 0;

        for(auto &it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int>inDegree(numCourses,0);

        for(int i = 0 ;i<numCourses;i++){
            for(auto &it :adj[i]){
                inDegree[it]++;
            }
        }

        queue<int>q;

        for(int i = 0 ;i<numCourses; i++){
            if(inDegree[i]==0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();q.pop();
            

            for(auto &it : adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                     q.push(it);
                     count++;
                }
            }
        }

        if(count == numCourses ){
            return true;
        }else{
            return false;
        }
    }
};