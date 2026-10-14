class Solution {
public:

    bool canEatAll(vector<int>&piles, int mid, int h){
        long long actualhours = 0;

        for(int &pile : piles){
            actualhours += pile/mid;

            if( pile%mid != 0){
                actualhours++;
            }
        }
        return actualhours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        

        while(low<=high){
            int mid = low + (high - low)/2;

            if(canEatAll(piles, mid, h)){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};