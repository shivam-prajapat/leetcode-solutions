class Solution {
public:
    int findmin(vector<int>&bloomDay){
        int min = INT_MAX;
        for(int i =0 ;i<bloomDay.size();i++){
            if(min>bloomDay[i]){
                min= bloomDay[i];
            }
        }
        return min;
    }

    long long findmax(vector<int>&bloomDay){
        long long max=0;
        for(int i =0;i<bloomDay.size();i++){
            if(max<bloomDay[i]){
                max=bloomDay[i];
            }

        }
        return max;
    }

    bool possible(vector<int>&bloomDay,int m,int k,int day){
        int count=0;
        int noOfB=0;
        for(int i =0 ;i<bloomDay.size();i++ ){
            if(bloomDay[i]<=day){
                count++;

            }else{
                noOfB+=(count/k);
                count=0;
            }
        }
        noOfB+=(count/k);
        if(noOfB>=m)return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) {
            return -1;
        }    
        int low = findmin(bloomDay);
        long long high = findmax(bloomDay);
        while(low<=high){
            int mid = low +(high  - low)/2;
            if (possible(bloomDay,m,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};