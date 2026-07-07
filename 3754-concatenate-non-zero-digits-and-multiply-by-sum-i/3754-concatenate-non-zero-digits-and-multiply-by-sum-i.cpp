class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        
        for (char ch : to_string(n)) {
            if (ch != '0') {
                sum += ch - '0';
                x = x * 10 + (ch - '0');
            }
        }
        
        return x * sum;
    }
};