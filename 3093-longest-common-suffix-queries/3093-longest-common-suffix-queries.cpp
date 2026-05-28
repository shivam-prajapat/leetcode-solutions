class Solution {
    struct Node {
        int children[26] = {0};
        int best_idx = 0;
    };
    
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int best_global = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[best_global].length()) {
                best_global = i;
            }
        }
        
        int total_chars = 0;
        for (const string& w : wordsContainer) {
            total_chars += w.length();
        }
        
        vector<Node> trie(total_chars + 2);
        trie[0].best_idx = best_global;
        int node_cnt = 1;
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            int curr = 0;
            int len = wordsContainer[i].length();
            
            for (int j = len - 1; j >= 0; --j) {
                int c = wordsContainer[i][j] - 'a';
                if (trie[curr].children[c] == 0) {
                    trie[curr].children[c] = node_cnt;
                    trie[node_cnt].best_idx = i;
                    node_cnt++;
                }
                curr = trie[curr].children[c];
                
                int best = trie[curr].best_idx;
                if (len < wordsContainer[best].length() || 
                   (len == wordsContainer[best].length() && i < best)) {
                    trie[curr].best_idx = i;
                }
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            for (int j = q.length() - 1; j >= 0; --j) {
                int c = q[j] - 'a';
                if (trie[curr].children[c] == 0) {
                    break;
                }
                curr = trie[curr].children[c];
            }
            ans.push_back(trie[curr].best_idx);
        }
        
        return ans;
    }
};