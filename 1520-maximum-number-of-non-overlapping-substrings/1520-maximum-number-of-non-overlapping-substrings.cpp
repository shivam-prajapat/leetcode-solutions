class Solution {
    int check(const string& s, int i, const vector<int>& l, const vector<int>& r) {
        int right = r[s[i] - 'a'];
        for (int j = i; j <= right; ++j) {
            if (l[s[j] - 'a'] < i) return -1;
            right = max(right, r[s[j] - 'a']);
        }
        return right;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, INT_MAX);
        vector<int> r(26, -1);
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        
        vector<string> res;
        int last_right = -1;
        
        for (int i = 0; i < n; ++i) {
            if (i == l[s[i] - 'a']) {
                int right = check(s, i, l, r);
                if (right != -1) {
                    if (i > last_right) {
                        res.push_back("");
                    }
                    last_right = right;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }
        
        return res;
    }
};