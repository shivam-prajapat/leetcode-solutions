class Solution {
public:
    int givesum(vector<int>&nums, int maxSum){
        int intcount = 1; int add = 0;

        for (int i = 0 ;i< nums.size();i++){
            if(nums[i]+add <= maxSum){
                add += nums[i];
            }else{
                intcount++;
                add = nums[i];
            }
        }
        return intcount;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while ( low <= high ){
            int mid = low + (high - low )/2;
            if( givesum(nums,mid)<= k){
                high = mid -1;
            }else {
                low = mid +1;
            }
        }
        return low;
    }
};