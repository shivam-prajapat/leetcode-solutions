class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                if (count > 0) result += c; // skip the outer '('
                count++;
            } else {
                count--;
                if (count > 0) result += c; // skip the outer ')'
            }
        }

        return result;
    }
};
