

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // When count becomes 0 → found a special substring
            if (count == 0) {
                // Recursively process inside part
                string inside = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inside) + "0");
                start = i + 1;
            }
        }

        // Sort in descending order
        sort(parts.begin(), parts.end(), greater<string>());

        // Combine
        string result;
        for (auto &p : parts) {
            result += p;
        }

        return result;
    }
};