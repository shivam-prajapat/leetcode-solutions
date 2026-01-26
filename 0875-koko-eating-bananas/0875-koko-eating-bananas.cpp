class Solution {
public:
    long long func(vector<int>&piles,int hourly){
        long long totalhours = 0;
        for(int i =0 ;i<piles.size();i++){
            totalhours += ceil((double)piles[i]/(double)hourly);
        }
        return totalhours;
    }
    int findmax(vector<int>&piles){
        int maxelement=INT_MIN;
        for(int i = 0 ;i<piles.size();i++){
            if(maxelement<piles[i]){
                maxelement=piles[i];
            }
        }
        return maxelement;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = findmax(piles);
        while(low<=high){
            int mid = low+(high-low)/2;
            long long reqtime=func(piles,mid);
            if(reqtime<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};