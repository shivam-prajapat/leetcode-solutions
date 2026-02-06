class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int i,j;

        for ( i = 1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                mini = min(mini,nums[i]);
            }
        }
        for( j = nums.size()-2 ;j>=0;j--){
            if(nums[j]>nums[j+1]){
                maxi = max(maxi,nums[j]);
            }
        }
        if(mini == INT_MAX && maxi == INT_MIN){
            return 0;
        }
        for( i = 0 ;i<nums.size();i++){
            if(nums[i]>mini){
                break;
            }
        }
        for( j = nums.size()-1; j>=0;j--){
            if(nums[j]<maxi){
                break;
            }
        }
        return j-i+1;

    }
};