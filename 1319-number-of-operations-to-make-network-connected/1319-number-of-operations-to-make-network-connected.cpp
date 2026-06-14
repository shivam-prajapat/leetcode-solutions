class Solution {
public:

    int find(int i, vector<int>&parent){
        if(parent[i]==i){
            return i;
        }

        return parent[i]= find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>&parent, vector<int>&rank){

        int x_parent = find(x,parent);
        int y_parent = find(y,parent);

        if(x_parent == y_parent){
            return;
        }

        if(rank[x_parent]>y_parent){
            parent[y_parent]=x_parent;
        }else if(rank[y_parent]>x_parent){
            parent[x_parent]=y_parent;
        }else{
            parent[y_parent]=x_parent;
            rank[x_parent]+=1;
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(!(connections.size()>= n-1)){
            return -1;
        }
        
        vector<int>parent(n);
        vector<int>rank(n,0);

        int components = n;

        for(int i = 0 ;i<n;i++){
            parent[i]=i;
        }


        for(auto it : connections){
            int first = it[0];
            int second = it[1];

            int parent_first = find(first,parent);
            int parent_second = find(second,parent);

            if(parent_first != parent_second){
                Union(first,second,parent,rank);
                components--;
            }
            if(parent_first == parent_second){
                continue;
            }
        }

        return components -1;
    }
};