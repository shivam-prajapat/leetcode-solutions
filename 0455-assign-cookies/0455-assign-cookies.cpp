class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   // children greed factors
        sort(s.begin(), s.end());   // cookie sizes

        int i = 0, j = 0;
        int n = g.size(), m = s.size();

        while (i < n && j < m) {
            if (s[j] >= g[i]) {  
                // this child is satisfied
                i++;
                j++;
            } else {
                // cookie too small → try larger cookie
                j++;
            }
        }
        return i;   // number of satisfied children
    }
};
