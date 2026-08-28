class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }

        if (odd_count > 1) return "";

        int h = n / 2;
        vector<int> half_freq(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_freq[i] = freq[i] / 2;
        }

        auto get_palindrome = [&](const string& left) {
            string res = left;
            if (n % 2 != 0) res += mid_char;
            string rev = left;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };

        vector<int> cur_freq = half_freq;
        int max_k = 0;
        for (int i = 0; i < h; ++i) {
            int idx = target[i] - 'a';
            if (cur_freq[idx] > 0) {
                cur_freq[idx]--;
                max_k = i + 1;
            } else {
                break;
            }
        }

        if (max_k == h) {
            string left = target.substr(0, h);
            string p = get_palindrome(left);
            if (p > target) {
                return p;
            }
        }

        cur_freq = half_freq;
        for (int i = 0; i < max_k; ++i) {
            cur_freq[target[i] - 'a']--;
        }

        for (int i = max_k; i >= 0; --i) {
            if (i < max_k) {
                cur_freq[target[i] - 'a']++;
            }

            if (i >= h) continue;

            int target_char = target[i] - 'a';
            for (int c = target_char + 1; c < 26; ++c) {
                if (cur_freq[c] > 0) {
                    string left = target.substr(0, i);
                    left += (char)('a' + c);

                    vector<int> rem_freq = cur_freq;
                    rem_freq[c]--;

                    for (int r = 0; r < 26; ++r) {
                        while (rem_freq[r] > 0) {
                            left += (char)('a' + r);
                            rem_freq[r]--;
                        }
                    }

                    return get_palindrome(left);
                }
            }
        }

        return "";
    }
};