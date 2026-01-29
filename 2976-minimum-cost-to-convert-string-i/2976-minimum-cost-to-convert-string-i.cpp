
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize the distance matrix with a very large value (infinity)
        // We use 26x26 because there are only lowercase English letters.
        const long long INF = 1e18;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // The cost to convert a character to itself is always 0
        for (int i = 0; i < 26; ++i) {
            dist[i][i] = 0;
        }

        // Populate initial conversion costs
        // We take the minimum cost if there are multiple defined conversions for the same pair
        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall Algorithm to find shortest paths between all pairs
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Calculate total cost to convert source to target
        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            // If the conversion is impossible, return -1
            if (dist[u][v] == INF) {
                return -1;
            }

            totalCost += dist[u][v];
        }

        return totalCost;
    }
};