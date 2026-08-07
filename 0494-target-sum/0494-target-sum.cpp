class Solution {
public:

    int solve(vector<int>&nums, int ind, int curSum, int target){
        if(ind == nums.size()){
            if(curSum == target){
                return 1;
            }
            return 0;
        }

        int plus = solve(nums, ind+1, curSum + nums[ind], target);
        int minus = solve(nums, ind+1, curSum - nums[ind], target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,0,target);
    }
};