class Solution {
public:
    void printSubsequence(vector<int>& nums,vector<int>&ds,vector<vector<int>>&ans,int n,int i){
        if(i==n){
            ans.push_back(ds);
            return;

        }
        
        ds.push_back(nums[i]);
        printSubsequence(nums,ds,ans,n,i+1);
        ds.pop_back();
        printSubsequence(nums,ds,ans,n,i+1);
        


    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        printSubsequence(nums,ds,ans,nums.size(),0);
        return ans;
    }
};