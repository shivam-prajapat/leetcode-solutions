class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 &&
               (n & (n - 1)) == 0 &&        // power of two
               (n & 0x55555555) != 0;       // bit in even position
    }
};
