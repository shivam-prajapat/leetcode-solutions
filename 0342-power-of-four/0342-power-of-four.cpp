class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)return false;
        double num =n;
        double t = log10(num)/log10(4.0);
        if(floor(t)==t)return true;
        return false;
    }
};

    

