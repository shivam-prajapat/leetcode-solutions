class Solution {
public:

    int find(int i,vector<int>&parent){
        if(parent[i]==i){
            return i;
        }

        return parent[i]=find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>&parent, vector<int>&rank){

        int x_parent = find(x,parent);
        int y_parent = find(y,parent);

        if( x_parent == y_parent){
            return;
        }

        if(rank[x_parent]>y_parent){
            parent[y_parent]=x_parent;
        }else if(rank[y_parent]>x_parent){
            parent[x_parent]=y_parent;
        }else{
            parent[y_parent]=x_parent;
            rank[y_parent]++;
        }


    }

    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        vector<int>rank(26,0);

        for(int i = 0 ;i<26;i++){
            parent[i]=i;
        }

        //first do union of  equal characters

        for(string &s : equations){
            if(s[1]=='='){//"a==b"
                Union(s[0]-'a',s[3]-'a',parent,rank);
            } 


        }

        //find != vale cases and check validity

        for(string &s : equations){
            if(s[1]=='!'){
                char first = s[0];
                char second = s[3];

                int first_parent = find(first-'a',parent);
                int second_parent = find(second-'a',parent);

                if(first_parent == second_parent){
                    return false;
                }
            }
        }

        return true;
    }
};