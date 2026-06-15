class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>result(n+1,INT_MAX);

        for(auto ed : times){
            int u = ed[0];
            int v = ed[1];
            int wt = ed[2];

            adj[u].push_back({v,wt});
        }

        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode= it.first;
                int dis = it.second;

                if(d+dis<result[adjNode]){
                    result[adjNode]=d+dis;
                    pq.push({d+dis,adjNode});

                }
            }
        }
        for(int i = 1 ;i<=n;i++){
            if(result[i]==INT_MAX){
                return -1;
            }
        }
        int maxi = *max_element(result.begin()+1,result.end());

        return maxi;


    }
};