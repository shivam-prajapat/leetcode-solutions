

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // Iterate over every possible starting position
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            
            // Expand the substring to the right
            for (int j = i; j < n; ++j) {
                // Update frequency for the current character
                freq[s[j] - 'a']++;
                
                // Check if the current window [i, j] is balanced
                int commonFreq = -1;
                bool isBalanced = true;
                
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        // If this is the first character we've seen, record its frequency
                        if (commonFreq == -1) {
                            commonFreq = freq[k];
                        } 
                        // If we see another character with a different frequency, it's not balanced
                        else if (freq[k] != commonFreq) {
                            isBalanced = false;
                            break;
                        }
                    }
                }
                
                if (isBalanced) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};