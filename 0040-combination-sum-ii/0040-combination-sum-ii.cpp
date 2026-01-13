class Solution {
public:
    void findCombination(vector<int>&candidates,int ind,int target, vector<vector<int>>&ans, vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            findCombination(candidates,i+1,target-candidates[i],ans,ds);
            ds.pop_back();

            }



    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>arr;
        
        findCombination(candidates,0,target,ans,arr);
        return ans;
    }
};