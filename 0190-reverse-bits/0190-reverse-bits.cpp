

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        // Loop through all 32 bits of the integer
        for (int i = 0; i < 32; ++i) {
            // 1. Shift result to the left to make room for the new bit
            result = result << 1;
            
            // 2. Get the last bit of n
            int bit = n & 1;
            
            // 3. Add that bit to the last position of result
            result = result | bit;
            
            // 4. Shift n to the right to process the next bit
            n = n >> 1;
        }
        
        return result;
    }
};