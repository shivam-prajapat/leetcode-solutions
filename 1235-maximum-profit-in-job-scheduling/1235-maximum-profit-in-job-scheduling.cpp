class Solution {
public:
int n ;
int dp[50001];

    int nextInd(vector<vector<int>>&arr,int l, int endTime){
        int r = n - 1;
        int res = n;

        while(l<=r){
            int mid = l + (r - l)/2;

            if(arr[mid][0]>=endTime){
                res = mid;
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }
        return res;
    }

    int solve(vector<vector<int>>&arr, int i ){
       

        if(i>= n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int taken = arr[i][2] + solve(arr,nextInd(arr,i+1,arr[i][1]));
        int skip = solve(arr,i+1);

        return dp[i] = max(taken, skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         n = startTime.size() ;
        vector<vector<int>> arr(n,vector<int>(3,0));
        
        for(int i = 0 ;i<n;i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];

        }
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));

        return solve(arr,0);
        
    }
};