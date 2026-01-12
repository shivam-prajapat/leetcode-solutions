class Solution {
public:
    void findCombinations(int i,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&ds,int target){
        if(i==candidates.size()){
            if(target==0) {
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            findCombinations(i,candidates,ans,ds,target-candidates[i]);
            ds.pop_back();   
        }

        findCombinations(i+1,candidates,ans,ds,target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(0,candidates,ans,ds,target);
        return ans;
       

    }
};