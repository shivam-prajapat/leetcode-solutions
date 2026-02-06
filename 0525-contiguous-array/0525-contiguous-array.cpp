class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int s = 0;
       int res = 0;
       map<int,int>mp;

       for(int i =0 ;i<nums.size();i++){
        s+=(nums[i]==0)? -1 : 1;
        if( s== 0) res = i+1;

        if(mp.find(s)!=mp.end()){
            res = max(res,i-mp[s]);
        }else{
            mp[s]=i;
        }
       }
       return res;
    }
};