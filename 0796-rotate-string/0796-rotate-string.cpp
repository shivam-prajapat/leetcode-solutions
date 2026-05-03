class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int n = s.size();

        for (int step = 0; step < n; step++) {
          
            char temp = s[0];
            for (int i = 0; i < n - 1; i++) {
                s[i] = s[i + 1];
            }
            s[n - 1] = temp; 

           
            int flag = 1; 
            for (int i = 0; i < n; i++) {
                if (s[i] != goal[i]) {
                    flag = 0; 
                    break;
                }
            }

            if (flag == 1) {
                return true;
            }
        }

        return false;
    }
};