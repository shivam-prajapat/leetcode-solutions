class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        result.reserve(words.size());
        
        for (const string& word : words) {
            int current_weight = 0;
            for (char c : word) {
                current_weight += weights[c - 'a'];
            }
            result.push_back(char('z' - (current_weight % 26)));
        }
        
        return result;
    }
};