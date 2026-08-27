class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int m = target.size();
        
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int max_l = 0;
        for (int i = 0; i < min(n, m); ++i) {
            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
                max_l = i + 1;
            } else {
                break;
            }
        }
        
        for (int l = max_l; l >= 0; --l) {
            if (l == m && l < n) {
                string res = target.substr(0, l);
                for (int c = 0; c < 26; ++c) {
                    res.append(freq[c], 'a' + c);
                }
                return res;
            }
            
            if (l < m && l < n) {
                int target_char = target[l] - 'a';
                int next_char = -1;
                for (int c = target_char + 1; c < 26; ++c) {
                    if (freq[c] > 0) {
                        next_char = c;
                        break;
                    }
                }
                
                if (next_char != -1) {
                    string res = target.substr(0, l);
                    res += (char)('a' + next_char);
                    freq[next_char]--;
                    for (int c = 0; c < 26; ++c) {
                        res.append(freq[c], 'a' + c);
                    }
                    return res;
                }
            }
            
            if (l > 0) {
                freq[target[l - 1] - 'a']++;
            }
        }
        
        return "";
    }
};