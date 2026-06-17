class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> len(n, 0);
        
        long long current_len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                current_len = max(0LL, current_len - 1);
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] != '%') {
                current_len += 1;
            }
            len[i] = current_len;
        }
        
        if (k >= len[n - 1]) return '.';
        
        for (int i = n - 1; i >= 0; --i) {
            long long prev_len = (i > 0) ? len[i - 1] : 0;
            
            if (s[i] == '#') {
                if (k >= prev_len) {
                    k -= prev_len;
                }
            } else if (s[i] == '%') {
                k = prev_len - 1 - k;
            } else if (s[i] != '*') {
                if (k == prev_len) {
                    return s[i];
                }
            }
        }
        
        return '.';
    }
};