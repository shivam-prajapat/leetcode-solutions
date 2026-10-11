class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() -1;

        while(low<high){
            int mid = low + (high - low)/2;

            bool isEven;

            if((high-mid)%2 == 0){
                isEven=true;
            }else{
                isEven = false;
            }

            if(nums[mid]==nums[mid+1]){

                if(isEven){
                    low = mid +2;
                }else{
                    high = mid-1;
                }
            }else{

                if(isEven){
                    high = mid;
                }else {
                    low = mid +1;
                }
            }

        }

        return nums[high];   
    }
};