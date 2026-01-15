class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)return false;
        double num =n;
        double t = log10(num)/log10(3.0);
        if(floor(t)==t)return true;
        return false;
    }
};
