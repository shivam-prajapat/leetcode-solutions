class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty())return 0;
        long long sum=std::accumulate(nums.begin(),nums.end(),0LL);
        int max_val=*std::max_element(nums.begin(),nums.end());
        return (long long )max_val*nums.size()-sum;
    }
};