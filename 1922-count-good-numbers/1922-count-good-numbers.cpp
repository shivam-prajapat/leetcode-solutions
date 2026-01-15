class Solution {
public:
    int M= 1e9 + 7;
    int findPower(long a, long b){
        if(b==0)return 1;
        long long half= findPower(a,b/2);
        long long res = (half* half)%M;
        if(b%2==1)res=(a*res)%M;

        return res;
    }
    int countGoodNumbers(long long n) {
        return (long long)findPower(5,(n+1)/2)* findPower(4,n/2) % M;
        
    }
};