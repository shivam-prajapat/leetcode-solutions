class Solution {
public:
    long long maxUnits(long long t, long long w) {
        // w * k*(k+1)/2 <= t
        long long left = 0, right = 1e6;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long time = w * mid * (mid + 1) / 2;

            if (time <= t)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 1, r = 1e18, ans = r;

        while (l <= r) {
            long long mid = (l + r) / 2;

            long long removed = 0;

            for (int w : workerTimes) {
                removed += maxUnits(mid, w);
                if (removed >= mountainHeight) break;
            }

            if (removed >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};