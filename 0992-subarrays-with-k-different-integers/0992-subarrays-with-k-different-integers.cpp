class Solution {
public:

    int solve(vector<int>& nums, int k ){
         int left = 0;
        int right = 0;
        int count = 0;

        unordered_map<int,int>mp;

        while(right<nums.size()){
            mp[nums[right]]++;

            while(mp.size()>k){
                mp[nums[left]]--;

                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }

            if(mp.size()<=k){
                count+=(right - left + 1);
            }
            right ++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return solve(nums, k ) - solve(nums,k - 1);
    }
};