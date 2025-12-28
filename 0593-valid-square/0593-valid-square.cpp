class Solution {
public:
    int dist(vector<int>& a, vector<int>& b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2,
                     vector<int>& p3, vector<int>& p4) {

        vector<vector<int>> points = {p1, p2, p3, p4};
        vector<int> d;

        // compute all 6 pairwise distances
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                d.push_back(dist(points[i], points[j]));
            }
        }

        sort(d.begin(), d.end());

        // first 4 should be equal and non-zero (sides)
        if (d[0] == 0) return false;

        return d[0] == d[1] &&
               d[1] == d[2] &&
               d[2] == d[3] &&
               d[4] == d[5];
    }
};
