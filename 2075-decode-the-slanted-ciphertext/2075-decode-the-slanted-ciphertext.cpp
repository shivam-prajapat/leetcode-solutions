class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        string ans = "";
        
        for (int c = 0; c < cols; c++) {
            int i = 0, j = c;
            while (i < rows && j < cols) {
                ans += encodedText[i * cols + j];
                i++;
                j++;
            }
        }
        
        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};