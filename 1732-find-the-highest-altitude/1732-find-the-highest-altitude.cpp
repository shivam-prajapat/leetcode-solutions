class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0;
        int current_alt = 0;
        
        for (int g : gain) {
            current_alt += g;
            max_alt = max(max_alt, current_alt);
        }
        
        return max_alt;
    }
};