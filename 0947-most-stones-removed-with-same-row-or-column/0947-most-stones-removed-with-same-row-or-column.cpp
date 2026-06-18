class Solution {
public:

    void DFS(int i, vector<int>&vis, vector<vector<int>>&stones){
        vis[i]=1;

        for(int j = 0 ;j<stones.size();j++){
            if(!vis[j] && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
                DFS(j,vis,stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n,0);

        int grp = 0;

        for(int i = 0 ;i<stones.size();i++){
       
                int u = stones[i][0];
                int v = stones[i][1];
                if(!vis[i]){
                    DFS(i,vis,stones);
                    grp++;

                }
            
        }

        return n-grp;
    }
};