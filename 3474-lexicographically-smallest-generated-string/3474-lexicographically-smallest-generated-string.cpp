

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int totalLen = n + m - 1;
        string res(totalLen, '?');

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != '?' && res[i + j] != str2[j]) {
                        return "";
                    }
                    res[i + j] = str2[j];
                }
            }
        }


        for (int i = 0; i < totalLen; ++i) {
            if (res[i] == '?') res[i] = 'a';
        }

     
     
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
               
               
                while (res.substr(i, m) == str2) {
                    
                    
                   
                    
                  
                  
                    bool fixed = false;
                    for (int j = m - 1; j >= 0; --j) {
 
 
                        if (!isFixedByT(str1, str2, i + j)) {
                            if (res[i + j] < 'z') {
                                res[i + j]++;
                                
                                
                                
                                
                                fixed = true;
                                break;
                            }
                        }
                    }
                    if (!fixed) return ""; 
                }
            }
        }

        return res;
    }

private:
    bool isFixedByT(const string& str1, const string& str2, int idx) {
        int n = str1.length();
        int m = str2.length();
        for (int i = max(0, idx - m + 1); i <= min(idx, n - 1); ++i) {
            if (str1[i] == 'T') return true;
        }
        return false;
    }
};