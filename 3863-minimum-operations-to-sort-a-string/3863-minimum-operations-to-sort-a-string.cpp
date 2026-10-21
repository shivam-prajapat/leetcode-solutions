class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        

        int flg = 1;
        for(int i = 1; i<n ;i++){
            if(s[i] < s[i-1]){
                flg = 0;
                break;
            }
        }
       

        if(flg) return 0;
        if(n== 2) return -1;

        char mnChar = 'z' + 1;
        char mxChar = 'a' -1;
        int mnCount = 0;
        int mxCount = 0;

        for (char c:s){
            mnChar = min(mnChar,c);
            mxChar = max(mxChar,c);
        }

        if(s[0] == mnChar || s[n-1] == mxChar){
            return 1;
        }

        for(char c : s) {
            if( c == mnChar ){
                mnCount ++;
            }
            if(c == mxChar){
                mxCount++;
            }
        }

        if(s[0] == mxChar && s[n-1] == mnChar && mnCount == 1 && mxCount == 1){
            return 3;
        }
        return 2;
        
    }
};