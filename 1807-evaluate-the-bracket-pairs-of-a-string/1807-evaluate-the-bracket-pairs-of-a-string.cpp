class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& k : knowledge) {
            dict[k[0]] = k[1];
        }
        
        string res;
        string key;
        bool inBracket = false;
        
        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key = "";
            } else if (c == ')') {
                inBracket = false;
                if (dict.count(key)) {
                    res += dict[key];
                } else {
                    res += '?';
                }
            } else {
                if (inBracket) {
                    key += c;
                } else {
                    res += c;
                }
            }
        }
        
        return res;
    }
};