class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

       // TOPOLOGICAL SORT METHOD

       int V = graph.size();

       vector<vector<int>>adj(V); 
       vector<int>inDeg(V,0);
       vector<int>safeNodes;

       for(int u = 0 ;u<V;u++){
        for(int v : graph[u]){
            adj[v].push_back(u);
            inDeg[u]++;
        }
       }

       queue<int>q;

       for(int i = 0 ;i<V;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
       }

       while(!q.empty()){
        int node = q.front();
        safeNodes.push_back(node);
        q.pop();

        for(auto it : adj[node]){
            inDeg[it]--;
            if(inDeg[it]==0){
                q.push(it);
            }
        }

       }

       sort(safeNodes.begin(),safeNodes.end());
       return safeNodes;
    }
};