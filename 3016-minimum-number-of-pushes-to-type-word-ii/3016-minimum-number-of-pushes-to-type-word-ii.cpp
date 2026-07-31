class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26, 0);
        for (char c : word) {
            counts[c - 'a']++;
        }
        
        sort(counts.rbegin(), counts.rend());
        
        int pushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 0) break;
            pushes += counts[i] * ((i / 8) + 1);
        }
        
        return pushes;
    }
};