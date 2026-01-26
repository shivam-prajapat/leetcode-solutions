class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int min=INT_MAX;
        for(int i =0 ;i<arr.size()-1;i++){
            int diff = arr[i+1]-arr[i];
            if(diff<min){
                min=diff;
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }else if(min==diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;


    }
};