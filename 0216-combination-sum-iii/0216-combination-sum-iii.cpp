class Solution {
public:
    void findComb(int i,int k,int sumTillNow,int n,vector<int>&ds,vector<vector<int>>&ans){
    
        if(sumTillNow==n){
            if(k==0){
                ans.push_back(ds);
            }
            return;
        }

        if(i==10)return;
        //pick
        sumTillNow+=i;
        ds.push_back(i);
        findComb(i+1,k-1,sumTillNow,n,ds,ans);
        sumTillNow-=i;
        ds.pop_back();

        //Not pick

        findComb(i+1,k,sumTillNow,n,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        findComb(1,k,0,n,ds,ans);
        return ans;
    }
};