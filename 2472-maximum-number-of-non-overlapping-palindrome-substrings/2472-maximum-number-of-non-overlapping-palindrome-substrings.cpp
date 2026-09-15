class Solution {
private:

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = 0; 
        for (int r = k - 1; r < n; ++r) {
            
            if (r - k + 1 >= last_end && isPalindrome(s, r - k + 1, r)) {
                count++;
                last_end = r + 1;
            }
           
            else if (r - k >= last_end && isPalindrome(s, r - k, r)) {
                count++;
                last_end = r + 1;
            }
        }

        return count;
    }
};