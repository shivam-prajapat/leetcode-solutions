

class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int reversedNum = 0;
        
     
        while (n > 0) {
            reversedNum = reversedNum * 10 + n % 10;
            n /= 10;
        }
        
    
        return std::abs(original - reversedNum);
    }
};