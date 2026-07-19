class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);


        vector<bool> in_res(26, false);
        
        for (char c : s) {
            count[c - 'a']++;
        }

        
        string res= "";
        for (char c : s) {
            count[c- 'a']--;
            
            if (in_res[c- 'a']) {
                continue;
            }

            
            while (!res.empty() && res.back() > c && count[res.back() - 'a'] > 0) {
                in_res[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            in_res[c - 'a'] = true;
        }


        
        return res;
    }
};