class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count =0;
        vector<int>missing;
        int start=nums.front();
        int end=nums.back();
        
        for(int i=start;i<=end;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                missing.push_back(i);
            }
            
        }
        return missing;
    }
};