class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCount = 0;
        int rCount = 0;
        int blankCount = 0;

        for (char c : moves) {
            if (c == 'L') {
                lCount++;
            } else if (c == 'R') {
                rCount++;
            } else {
                blankCount++;
            }
        }

 
        return std::abs(lCount - rCount) + blankCount;
    }
};