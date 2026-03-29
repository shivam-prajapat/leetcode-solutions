class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string a1 = "", a2 = "", b1 = "", b2 = "";
        
        for(int i = 0; i < 4; i++) {
            if(i % 2 == 0) {
                a1 += s1[i];
                a2 += s2[i];
            } else {
                b1 += s1[i];
                b2 += s2[i];
            }
        }
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        
        return a1 == a2 && b1 == b2;
    }
};