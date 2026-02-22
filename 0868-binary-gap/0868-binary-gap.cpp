class Solution {
public:
    int binaryGap(int n) {
        int last = -1;      // stores index of previous 1
        int index = 0;      // current bit position
        int maxGap = 0;

        while (n > 0) {
            if (n & 1) {            // if current bit is 1
                if (last != -1) {
                    maxGap = max(maxGap, index - last);
                }
                last = index;
            }
            n >>= 1;                // right shift
            index++;
        }

        return maxGap;
    }
};