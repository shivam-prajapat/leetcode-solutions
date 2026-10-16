class Solution {
public:

    int findDay(vector<int>& weights, int capacity){
        int Days = 1;
        int sum = 0;

        for(int i = 0 ;i<weights.size();i++){
            if(sum + weights[i]>capacity){
                sum = weights[i];
                Days++;
            }else{
                sum+=weights[i];
            }
        }
        return Days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for(int i = 0 ;i<weights.size(); i++) {
            high += weights[i];
        }

        while(low<=high){
            int mid = low + (high - low)/2;

            if( findDay(weights, mid)<=days){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }

        return low;
    }
};