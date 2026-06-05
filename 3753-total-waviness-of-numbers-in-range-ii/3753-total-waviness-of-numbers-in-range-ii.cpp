class Solution {
    struct Result {
        long long count;
        long long sum;
    };
    
    Result memo[25][2][11][11];
    bool visited[25][2][11][11];
    
    Result dfs(const string& s, int idx, bool tight, bool lz, int last_digit, int sec_last_digit) {
        if (idx == s.length()) {
            return {1, 0};
        }
        
        if (!tight && visited[idx][lz][last_digit][sec_last_digit]) {
            return memo[idx][lz][last_digit][sec_last_digit];
        }
        
        int limit = tight ? (s[idx] - '0') : 9;
        Result res = {0, 0};
        
        for (int d = 0; d <= limit; d++) {
            bool next_lz = lz && (d == 0);
            int next_last = next_lz ? 10 : d;
            int next_sec_last = next_lz ? 10 : (lz ? 10 : last_digit);
            
            long long added_waviness = 0;
            if (!lz && sec_last_digit != 10 && last_digit != 10) {
                if (last_digit > sec_last_digit && last_digit > d) added_waviness = 1;
                if (last_digit < sec_last_digit && last_digit < d) added_waviness = 1;
            }
            
            Result child = dfs(s, idx + 1, tight && (d == limit), next_lz, next_last, next_sec_last);
            
            res.count += child.count;
            res.sum += child.sum + added_waviness * child.count;
        }
        
        if (!tight) {
            visited[idx][lz][last_digit][sec_last_digit] = true;
            memo[idx][lz][last_digit][sec_last_digit] = res;
        }
        
        return res;
    }
    
    long long solve(string s) {
        memset(visited, 0, sizeof(visited));
        return dfs(s, 0, true, true, 10, 10).sum;
    }
    
public:
    long long totalWaviness(long long num1, long long num2) {
        long long right = solve(to_string(num2));
        long long left = (num1 > 0) ? solve(to_string(num1 - 1)) : 0;
        return right - left;
    }
};