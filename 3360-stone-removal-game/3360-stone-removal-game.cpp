class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceTurn = true;
        
        while (stones > 0 && n >= stones) {
            n -= stones;
            stones--;
            aliceTurn = !aliceTurn;
        }
        
        return !aliceTurn;
    }
};