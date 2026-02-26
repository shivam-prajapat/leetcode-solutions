class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Start from last bit and go till second bit
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) % 2 == 0) {
                // Even case -> divide by 2
                steps += 1;
            } else {
                // Odd case -> add 1 then divide
                steps += 2;
                carry = 1;
            }
        }
        
        // If carry remains, add one more step
        return steps + carry;
    }
};