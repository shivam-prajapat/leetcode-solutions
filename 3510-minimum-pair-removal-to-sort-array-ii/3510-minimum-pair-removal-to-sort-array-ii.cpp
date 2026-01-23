class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // 1. Simulate Doubly Linked List
        // vals stores the current value of the node
        // next[i] and prev[i] store indices of neighbors
        vector<long long> vals(nums.begin(), nums.end());
        vector<int> next(n), prev(n);
        vector<bool> active(n, true); // Tracks valid nodes

        for (int i = 0; i < n; ++i) {
            next[i] = i + 1;
            prev[i] = i - 1;
        }
        next[n - 1] = -1; // End marker

        // Helper to check inversion between node i and its current next
        auto is_inverted = [&](int i) {
            if (i == -1 || next[i] == -1 || !active[i]) return false;
            return vals[i] > vals[next[i]];
        };

        // 2. Count initial inversions
        int inversions = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (is_inverted(i)) inversions++;
        }

        if (inversions == 0) return 0;

        // 3. Min-Heap: {sum, index}
        // standard 'greater' sorts pairs by min sum first, then min index (leftmost)
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        for (int i = 0; i < n - 1; ++i) {
            pq.push({vals[i] + vals[next[i]], i});
        }

        int ops = 0;

        while (inversions > 0 && !pq.empty()) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = next[i]; // The right node to be merged

            // Validation:
            // 1. Node i must be active
            // 2. Node j (next[i]) must exist (not -1) and match logic
            // 3. Stale Check: The sum in heap must match current reality
            if (!active[i] || j == -1 || vals[i] + vals[j] != sum) {
                continue;
            }

            // --- PERFORM MERGE ---
            
            // 1. Update Inversion Count (Remove old relations)
            if (prev[i] != -1 && is_inverted(prev[i])) inversions--; // Left neighbor relation
            if (is_inverted(i)) inversions--;                       // The pair itself (i, j)
            if (is_inverted(j)) inversions--;                       // Right neighbor relation

            // 2. Merge values (i absorbs j)
            vals[i] += vals[j];
            active[j] = false; // Mark j as removed

            // 3. Update Pointers (Remove j from list)
            int k = next[j]; // The node after j
            next[i] = k;
            if (k != -1) prev[k] = i;

            // 4. Update Inversion Count (Add new relations)
            if (prev[i] != -1 && is_inverted(prev[i])) inversions++;
            if (is_inverted(i)) inversions++;

            ops++;

            // 5. Push new potential pairs
            // New pair with left neighbor
            if (prev[i] != -1) {
                pq.push({vals[prev[i]] + vals[i], prev[i]});
            }
            // New pair with right neighbor (which is now k)
            if (next[i] != -1) {
                pq.push({vals[i] + vals[next[i]], i});
            }
        }

        return ops;
    }
};