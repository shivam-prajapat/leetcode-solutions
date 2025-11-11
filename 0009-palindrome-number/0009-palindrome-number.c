bool isPalindrome(int x) {
    if (x < 0) return false;

    long long  res = 0;
    int prex = x;

    while (x > 0) {
        int rem = x % 10;
        res = (res * 10) + rem;
        x /= 10;
    }

    return res == prex;
}
