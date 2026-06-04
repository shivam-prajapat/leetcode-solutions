class Solution {
    int wave(string s) {
        if (s.length() <= 2) return 0;
        int a = 0;
        for (int i = 1; i < s.length() - 1; i++) {
            if (((s[i - 1] > s[i]) && (s[i + 1] > s[i])) || 
                ((s[i - 1] < s[i]) && (s[i + 1] < s[i]))) {
                a++;
            }
        }
        return a;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += wave(to_string(i));
        }
        return ans;
    }
};