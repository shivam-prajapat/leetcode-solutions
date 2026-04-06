class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxlen = 0; 
        unordered_map<int,int>mp;
        int freq = 0;
    

        while(right<s.size()){
           mp[s[right]-'A']++;
           freq = max(freq,mp[s[right]-'A']);
          

           while( (right - left +1) - freq > k){
            mp[s[left] - 'A']--;
            left++;

            
           }
          
           if((right - left +1) - freq  <= k){
            maxlen = max(maxlen , right - left + 1);
           }
           right ++;


        }
        return maxlen;
    }
};