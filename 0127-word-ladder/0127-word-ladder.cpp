class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

       

        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        if(st.find(endWord)==st.end()){
            return 0;
        }


        while(!q.empty()){

            string currword = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 0 ; i<currword.size();i++){
                string word = currword;

                for(char ch = 'a';ch<='z' ;ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        if(word == endWord){
                            return step+1;
                        }
                        q.push({word,step+1});
                        st.erase(word);
                    }
                   
                }
            }
        }
        return 0;
        
    }
};