class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";          // acts like a stack
        int m = part.size();

        for (char ch : s) {
            result += ch;            // push character

            // Check if last m characters match 'part'
            if (result.size() >= m) {
                bool same = true;
                for (int i = 0; i < m; i++) {
                    if (result[result.size() - m + i] != part[i]) {
                        same = false;
                        break;
                    }
                }

                // if matched, remove them
                if (same) {
                    for (int i = 0; i < m; i++) {
                        result.pop_back();   // remove from end
                    }
                }
            }
        }
        return result;
    }
};