class Solution {
public:
    long long reverseDegree(string s) {
        long long totalDegree = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            long long charVal = 'z' - s[i] + 1; 
            long long posVal = i + 1;          
            totalDegree += charVal * posVal;
        }
        
        return totalDegree;
    }
};