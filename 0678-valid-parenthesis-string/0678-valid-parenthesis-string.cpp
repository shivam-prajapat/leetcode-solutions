class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        
        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin = max(0, cmin - 1);
            } else {
                cmax++;
                cmin = max(0, cmin - 1);
            }
            
            if (cmax < 0) {
                return false;
            }
        }
        
        return cmin == 0;
    }
};