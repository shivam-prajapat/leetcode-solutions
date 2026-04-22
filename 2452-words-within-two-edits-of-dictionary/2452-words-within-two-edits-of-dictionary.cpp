class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
      
        for (const string& query : queries) {
       
            for (const string& dictWord : dictionary) {
                int diffCount = 0;
                
                for (int i = 0; i < query.length(); ++i) {
                    if (query[i] != dictWord[i]) {
                        diffCount++;
                    }
                }
                
               
                if (diffCount <= 2) {
                    result.push_back(query);
                    break; 
                }
            }
        }
        
        return result;
    }
};