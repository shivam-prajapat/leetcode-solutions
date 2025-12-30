class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // step 1: put all words in a set for fast lookup
        unordered_set<string>st(wordList.begin(),wordList.end());

        // if endword is not present answer is impossible 

        if(st.find(endWord)==st.end()) return 0;

        // step 2: BFS ->queue{word,level}

        queue<pair<string,int>>q;

        q.push({beginWord,1});

        //Remove beginWord to avoid repetiton 

        st.erase(beginWord);

        //Step 3 : BFS trversal

        while(!q.empty()){
            auto[word,level]=q.front();
            q.pop();

            //if we reached endword

            if(word==endWord) return level;

            //step 4: change each character

            for(int i=0;i<word.size();i++){

                char original=word[i];

                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;

                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                //restore original character
                word[i]=original;
            }
        }
        return 0;
        
    }
};