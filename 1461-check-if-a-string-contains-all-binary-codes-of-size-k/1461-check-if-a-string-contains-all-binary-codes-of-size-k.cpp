class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        unordered_set<int> seen;
        int total = 1 << k;  // 2^k possible combinations
        
        int hash = 0;
        
        for (int i = 0; i < n; i++) {
            // Left shift and add current bit
            hash = ((hash << 1) & (total - 1)) | (s[i] - '0');
            
            // Start storing after first k characters
            if (i >= k - 1) {
                seen.insert(hash);
                
                if (seen.size() == total)
                    return true;
            }
        }
        
        return false;
    }
};