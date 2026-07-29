class Solution {
    long long nCr(int n, int r, long long limit) {
        if (r < 0 || r > n) return 0;
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > limit) return limit + 1;
        }
        return res;
    }

    long long countWays(const vector<int>& cnt, long long limit) {
        long long ways = 1;
        int total_len = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                total_len += cnt[i];
                long long combos = nCr(total_len, cnt[i], limit);
                if (limit / ways < combos) return limit + 1;
                ways *= combos;
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string left = "";
        char mid = 0;
        
        vector<int> cnt(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                mid = i + 'a';
            }
            cnt[i] = count[i] / 2;
        }
        
        long long target = k;
        long long total = countWays(cnt, target);
        if (total < target) {
            return "";
        }
        
        int halfLen = n / 2;
        for (int i = 0; i < halfLen; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0) continue;
                
                cnt[c]--;
                long long ways = countWays(cnt, target);
                
                if (target <= ways) {
                    left.push_back((char)('a' + c));
                    break;
                } else {
                    target -= ways;
                    cnt[c]++;
                }
            }
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        
        if (n % 2 != 0 && mid != 0) {
            return left + mid + right;
        }
        
        return left + right;
    }
};