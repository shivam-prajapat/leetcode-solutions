class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;

        for (string s : sentences) {
            int count = 1; // at least one word
            for (char c : s) {
                if (c == ' ')
                    count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
