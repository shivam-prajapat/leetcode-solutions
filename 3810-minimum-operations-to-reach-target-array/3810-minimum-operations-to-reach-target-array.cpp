class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        set<int>st;
        for(int i=0 ;i<nums.size();i++){
            if(nums[i]!=target[i]){
                if(st.find(nums[i])==st.end()){
                    st.insert(nums[i]);

                }
            }
        }
        return st.size();
        
    }
};