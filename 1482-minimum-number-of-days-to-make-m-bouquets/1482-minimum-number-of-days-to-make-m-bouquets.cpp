class Solution {
public:

    bool makeBow(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int noofBow = 0;

        for(int i = 0 ;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                noofBow += (count/k);
                count = 0;
            }
        }

        noofBow += (count/k);

        return noofBow>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int result = -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(makeBow(bloomDay, mid, m , k)){
                result = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }

        return result;
    }
};