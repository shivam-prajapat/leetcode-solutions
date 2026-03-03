class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case
        if (n == 1) return '0';
        
        int length = (1 << n) - 1;          // 2^n - 1
        int middle = (length / 2) + 1;      // 2^(n-1)
        
        if (k == middle)
            return '1';
        else if (k < middle)
            return findKthBit(n - 1, k);
        else {
            char ch = findKthBit(n - 1, length - k + 1);
            return (ch == '0') ? '1' : '0';   // invert
        }
    }
};