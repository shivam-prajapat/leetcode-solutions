class Solution {
    int memo[65][45];
    int get_min(int r2, int r3) {
        if (r2 <= 0 && r3 <= 0) return 0;
        if (memo[r2][r3] != -1) return memo[r2][r3];
        
        int res = 1e9;
        int transitions[6][2] = {{1,0}, {0,1}, {2,0}, {1,1}, {3,0}, {0,2}};
        
        for (auto& t : transitions) {
            int nr2 = max(0, r2 - t[0]);
            int nr3 = max(0, r3 - t[1]);
            if (nr2 == r2 && nr3 == r3) continue;
            res = min(res, 1 + get_min(nr2, nr3));
        }
        
        return memo[r2][r3] = res;
    }
    
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        if (temp > 1) return "-1";

        memset(memo, -1, sizeof(memo));

        int twos[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int threes[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        int fives[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        int sevens[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

        int n = num.length();
        int first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            p2[i + 1] = p2[i] + twos[d];
            p3[i + 1] = p3[i] + threes[d];
            p5[i + 1] = p5[i] + fives[d];
            p7[i + 1] = p7[i] + sevens[d];
        }

        if (first_zero == n) {
            if (p2[n] >= req2 && p3[n] >= req3 && p5[n] >= req5 && p7[n] >= req7) {
                return num;
            }
        }

        for (int i = min(n - 1, first_zero); i >= 0; --i) {
            int pref2 = p2[i];
            int pref3 = p3[i];
            int pref5 = p5[i];
            int pref7 = p7[i];

            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                int cr2 = max(0, req2 - pref2 - twos[d]);
                int cr3 = max(0, req3 - pref3 - threes[d]);
                int cr5 = max(0, req5 - pref5 - fives[d]);
                int cr7 = max(0, req7 - pref7 - sevens[d]);

                int S = n - i - 1;
                if (get_min(cr2, cr3) + cr5 + cr7 <= S) {
                    string rem = "";
                    rem.reserve(S);
                    for (int pos = 0; pos < S; ++pos) {
                        for (int nd = 1; nd <= 9; ++nd) {
                            int nr2 = max(0, cr2 - twos[nd]);
                            int nr3 = max(0, cr3 - threes[nd]);
                            int nr5 = max(0, cr5 - fives[nd]);
                            int nr7 = max(0, cr7 - sevens[nd]);
                            if (get_min(nr2, nr3) + nr5 + nr7 <= S - pos - 1) {
                                rem.push_back('0' + nd);
                                cr2 = nr2; cr3 = nr3; cr5 = nr5; cr7 = nr7;
                                break;
                            }
                        }
                    }
                    return num.substr(0, i) + char('0' + d) + rem;
                }
            }
        }

        int S = max(n + 1, req5 + req7 + get_min(req2, req3));
        string ans = "";
        ans.reserve(S);
        int cr2 = req2, cr3 = req3, cr5 = req5, cr7 = req7;
        for (int pos = 0; pos < S; ++pos) {
            for (int nd = 1; nd <= 9; ++nd) {
                int nr2 = max(0, cr2 - twos[nd]);
                int nr3 = max(0, cr3 - threes[nd]);
                int nr5 = max(0, cr5 - fives[nd]);
                int nr7 = max(0, cr7 - sevens[nd]);
                if (get_min(nr2, nr3) + nr5 + nr7 <= S - pos - 1) {
                    ans.push_back('0' + nd);
                    cr2 = nr2; cr3 = nr3; cr5 = nr5; cr7 = nr7;
                    break;
                }
            }
        }
        return ans;
    }
};