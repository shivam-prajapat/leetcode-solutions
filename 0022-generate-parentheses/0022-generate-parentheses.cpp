class Solution {
public:
    vector<string> result;

    void solve(string current, int open, int close, int n) {
        // Base case: when the string length is 2*n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Try to add '(' if we still can
        if (open < n) {
            solve(current + "(", open + 1, close, n);
        }

        // Try to add ')' only if it won't break validity
        if (close < open) {
            solve(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return result;
    }
};
