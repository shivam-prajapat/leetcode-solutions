class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {
            int divSum = 0;
            int count = 0;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int j = n / i;

                    if (i == j) {
                        count += 1;
                        divSum += i;
                    } else {
                        count += 2;
                        divSum += i + j;
                    }

                    // early stop if more than 4 divisors
                    if (count > 4) break;
                }
            }

            if (count == 4) {
                totalSum += divSum;
            }
        }
        return totalSum;
    }
};
