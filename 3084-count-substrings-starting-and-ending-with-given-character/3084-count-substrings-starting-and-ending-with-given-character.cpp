class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long substr = 0;
        long long count = 0;

        for(int i = 0;i< s.size();i++){
            if(s[i]==c){
                substr += (1 + count);
                count++;
            }
        }
        return substr;
    }
};