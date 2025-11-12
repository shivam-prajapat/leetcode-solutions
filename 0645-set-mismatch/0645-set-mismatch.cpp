class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int miss=-1,dup=-1;
       vector<int>freq(nums.size()+1,0);
       for(int num:nums){
        freq[num]++;
       }

       for(int i=0;i<=nums.size();i++){
        if(freq[i]==2)dup=i;
        if(freq[i]==0)miss=i;
       }
       return {dup,miss};

    }
};