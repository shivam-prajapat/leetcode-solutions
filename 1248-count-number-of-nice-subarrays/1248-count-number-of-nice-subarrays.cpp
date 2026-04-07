class Solution {
public:

    int solve(vector<int>&nums, int k){
        int left = 0;
        int right = 0 ;
        int count = 0 ;
        int sum = 0;

        while(right < nums.size() ){
            if(nums[right]%2 != 0){
                sum++;
            }
            while(sum>k){
                if(nums[left]%2!=0){
                    sum -= 1;
                }
                left++;
            }

            count +=(right - left + 1);
            right ++;

        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)- solve(nums,k-1);
    }
};