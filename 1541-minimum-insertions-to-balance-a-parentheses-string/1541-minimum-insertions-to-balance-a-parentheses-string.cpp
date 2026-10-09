class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int open = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    res++;
                }
                
                if (open > 0) {
                    open--;
                } else {
                    res++;
                }
            }
        }
        
        res += open * 2;
        return res;
    }
};