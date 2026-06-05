class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,1});

        string choice = "ACGT";

        //Base case

        if(st.find(endGene)==st.end()){
            return -1;
        }

        while(!q.empty()){
            string currGene=q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 0 ;i<8;i++){
                string gene = currGene;
                for(char ch : choice){
                    gene[i]=ch;
                    if(st.find(gene)!=st.end()){
                        if(gene==endGene){
                            return step;
                        }
                        q.push({gene,step+1});
                        st.erase(gene);
                    }
                }
                

            }
            
        }
        return -1;
    }
};