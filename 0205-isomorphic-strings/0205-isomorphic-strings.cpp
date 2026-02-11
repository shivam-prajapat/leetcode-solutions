class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mapST;
        unordered_map<char,char>mapTS;

        for(int i = 0;i<s.size();i++){
            char a = s[i];
            char b = t[i];
            
            if(mapST.count(a)){
                if(mapST[a]!=b)return false;
            }else{
                mapST[a]=b;
            }
            if(mapTS.count(b)){
                if(mapTS[b]!=a)return false;
            }else{
                mapTS[b]=a;
            }
        }
        return true;
    }
};