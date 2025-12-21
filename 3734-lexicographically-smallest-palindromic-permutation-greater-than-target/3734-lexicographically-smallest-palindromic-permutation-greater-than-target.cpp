class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        string calendrix = s;
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }
        if (odd > 1) return "";
        vector<int> halfCount(26, 0);
        for (int i = 0; i < 26; ++i) halfCount[i] = freq[i] / 2;
        int k = n / 2;
        string prefix = "";

        auto build_from_half = [&](const string &h) {
            string res = h;
            if (n % 2 == 1 && mid) res.push_back(mid);
            res.append(string(h.rbegin(), h.rend()));
            return res;
        };

        auto make_min_half = [&](const vector<int>& hc) {
            string t;
            for (int c = 0; c < 26; ++c) if (hc[c]) t.append(hc[c], 'a' + c);
            return t;
        };
        auto make_max_half = [&](const vector<int>& hc) {
            string t;
            for (int c = 25; c >= 0; --c) if (hc[c]) t.append(hc[c], 'a' + c);
            return t;
        };

        for (int pos = 0; pos < k; ++pos) {
            bool placed = false;
            for (int ch = 0; ch < 26; ++ch) {
                if (halfCount[ch] == 0) continue;
                halfCount[ch]--;
                string minRem = make_min_half(halfCount);
                string maxRem = make_max_half(halfCount);

                string candMin = prefix + char('a' + ch) + minRem;
                string candMax = prefix + char('a' + ch) + maxRem;

                string fullMin = build_from_half(candMin);
                string fullMax = build_from_half(candMax);

                if (fullMax <= target) {
                    halfCount[ch]++; 
                    continue;
                }

                prefix.push_back('a' + ch);
                placed = true;
                break;
            }
            if (!placed) return "";
        }

        string finalPal = build_from_half(prefix);
        if (finalPal > target) return finalPal;

        return "";
    }
};
