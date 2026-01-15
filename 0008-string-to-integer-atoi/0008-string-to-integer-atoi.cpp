class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        long num = 0;
        int sign=1;

        //skip leading spaces
        while(i<n && s[i]==' '){
            i++;
        }
        //check sign
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-')sign =-1;
            i++;
        }
        //convert digit to number
        while(i<n && isdigit(s[i])){
            num =num *10 +(s[i]-'0');
            
            //handle overflow
            if(num*sign >= INT_MAX)return INT_MAX;
            if(num*sign <= INT_MIN)return INT_MIN;
            i++;
        }
        return sign *num;
    }
};