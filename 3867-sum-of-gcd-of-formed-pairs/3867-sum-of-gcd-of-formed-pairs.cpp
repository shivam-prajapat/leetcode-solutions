class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        vector<int> prefixGcd(n);

        for(int i = 0;i<n;i++){
            maxi = max(maxi , nums[i]);
            prefixGcd[i]=__gcd(nums[i],maxi);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int i = 0;
        int j = n -1;
        long long res = 0;

        while(i<j){
            res+=__gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return res;
    }
};