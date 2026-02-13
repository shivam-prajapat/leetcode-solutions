

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        // --- Case 1: Substrings with 1 distinct character ---
        // A substring with 1 distinct char is always balanced.
        // We just need the longest consecutive run.
        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            max_len = max(max_len, current_run);
        }

        // --- Case 2: Substrings with 2 distinct characters ---
        // Combinations: {'a', 'b'}, {'a', 'c'}, {'b', 'c'}
        // We verify each pair separately.
        char pairs[3][2] = {{'a', 'b'}, {'a', 'c'}, {'b', 'c'}};
        
        for (auto& p : pairs) {
            char c1 = p[0];
            char c2 = p[1];
            
            // Iterate through s, processing segments that ONLY contain c1 or c2.
            // Any other character acts as a reset/delimiter.
            for (int i = 0; i < n; ) {
                if (s[i] != c1 && s[i] != c2) {
                    i++;
                    continue;
                }
                
                // Identify the segment [i, j-1] containing only c1 and c2
                int j = i;
                while (j < n && (s[j] == c1 || s[j] == c2)) {
                    j++;
                }
                
                // Solve "Longest Subarray with Sum 0" for this segment
                // c1 is +1, c2 is -1.
                // Using a vector instead of map for O(1) access. 
                // Offset is needed because balance can be negative.
                int seg_len = j - i;
                // Initialize with -2 to represent "unseen". 
                // Size is 2*len+1 to cover range [-len, +len].
                vector<int> seen(2 * seg_len + 1, -2);
                int offset = seg_len;
                
                // Base case: balance 0 is seen at virtual index i-1
                seen[0 + offset] = i - 1; 
                
                int balance = 0;
                for (int k = i; k < j; ++k) {
                    balance += (s[k] == c1 ? 1 : -1);
                    
                    if (seen[balance + offset] != -2) {
                        max_len = max(max_len, k - seen[balance + offset]);
                    } else {
                        seen[balance + offset] = k;
                    }
                }
                
                // Move i to the end of the current segment
                i = j;
            }
        }

        // --- Case 3: Substrings with 3 distinct characters ---
        // We need count('a') == count('b') == count('c')
        // We track differences: d1 = a - b, d2 = b - c
        // If (d1, d2) repeats, the substring between occurrences has equal counts of a, b, and c.
        map<pair<int, int>, int> seen_diffs;
        seen_diffs[{0, 0}] = -1;
        
        int ca = 0, cb = 0, cc = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;
            
            int d1 = ca - cb;
            int d2 = cb - cc;
            
            if (seen_diffs.count({d1, d2})) {
                max_len = max(max_len, i - seen_diffs[{d1, d2}]);
            } else {
                seen_diffs[{d1, d2}] = i;
            }
        }

        return max_len;
    }
};