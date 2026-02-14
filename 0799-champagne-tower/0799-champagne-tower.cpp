
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Create a 2D vector to store the amount of champagne in each glass.
        // We size it to query_row + 2 to safely handle the "overflow" into the next row
        // without checking for boundary conditions constantly.
        vector<vector<double>> tower(query_row + 2, vector<double>(query_row + 2, 0.0));

        // Pour the initial amount into the top glass
        tower[0][0] = (double)poured;

        // Iterate through each row up to the one before query_row
        // (We only need to process overflows FROM rows 0 to query_row-1 
        // to populate row query_row)
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                // If the current glass has overflowed (more than 1 cup)
                double excess = (tower[r][c] - 1.0) / 2.0;
                
                if (excess > 0) {
                    // Distribute the excess to the two glasses below
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }

        // The glass can hold at most 1 cup. If it received more, the answer is 1.
        return min(1.0, tower[query_row][query_glass]);
    }
};