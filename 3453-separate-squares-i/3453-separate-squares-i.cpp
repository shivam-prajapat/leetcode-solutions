class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        // Determine search range
        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + sq[2]);
        }

        // Binary search
        for (int iter = 0; iter < 100; iter++) {
            double mid = (low + high) / 2.0;
            double above = 0.0, below = 0.0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];

                if (mid <= y) {
                    above += l * l;
                } else if (mid >= y + l) {
                    below += l * l;
                } else {
                    above += l * (y + l - mid);
                    below += l * (mid - y);
                }
            }

            if (above > below)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }
};
