class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>output;


        for(int i = 0 ;i<nums.size();i++){

            //if the window is out of bound remove krna h front element ko
            if(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k-1){
                int cur_max = nums[dq.front()];
                output.push_back(cur_max); 
            }
        }
        return output;
    }
};