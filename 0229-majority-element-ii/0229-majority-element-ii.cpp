class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            if(count1==0 && nums[i]!=element2){
                count1+=1;
                element1 = nums[i];
            }else if(count2 == 0 && nums[i]!=element1){
                count2+=1;
                element2 = nums[i];
            }else if (nums[i]==element1) count1++;
            else if (nums[i]==element2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0,count2 = 0;
        for(int x : nums){
            if(x==element1)count1++;
            if(x==element2)count2++;
        }
        
        vector<int>ans;
        if(count1>floor(nums.size()/3)){
        ans.push_back(element1);
        }
        if(count2>floor(nums.size()/3)){
        ans.push_back(element2);
        }
        return ans;
    }
};