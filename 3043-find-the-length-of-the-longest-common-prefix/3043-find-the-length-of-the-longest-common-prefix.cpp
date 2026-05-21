class Solution {
    struct TrieNode {
        TrieNode* children[10];
        TrieNode() {
            for (int i = 0; i < 10; ++i) {
                children[i] = nullptr;
            }
        }
    };
    
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        
        for (int num : arr1) {
            string s = to_string(num);
            TrieNode* node = root;
            for (char c : s) {
                int idx = c - '0';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
        }
        
        int max_len = 0;
        
        for (int num : arr2) {
            string s = to_string(num);
            TrieNode* node = root;
            int current_len = 0;
            
            for (char c : s) {
                int idx = c - '0';
                if (node->children[idx]) {
                    current_len++;
                    node = node->children[idx];
                } else {
                    break;
                }
            }
            
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
        
        return max_len;
    }
};