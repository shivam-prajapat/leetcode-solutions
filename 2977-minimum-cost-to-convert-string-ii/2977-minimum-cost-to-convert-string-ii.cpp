class Solution {
    // Trie Node structure to efficiently store rule strings
    struct TrieNode {
        TrieNode* children[26];
        int id; // Maps the string ending here to a unique integer ID
        TrieNode() {
            fill(begin(children), end(children), nullptr);
            id = -1;
        }
    };

    // Helper to insert a string into the Trie and assign its ID
    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->id = id;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        // 1. Map all unique substrings involved in rules to integer IDs
        unordered_map<string, int> strToId;
        int nextId = 0;
        
        auto getId = [&](const string& s) {
            if (strToId.find(s) == strToId.end()) {
                strToId[s] = nextId++;
            }
            return strToId[s];
        };

        // Initialize Trie
        TrieNode* root = new TrieNode();
        
        // Populate Trie and ID map with all strings from 'original' and 'changed'
        for (const string& s : original) insert(root, s, getId(s));
        for (const string& s : changed)  insert(root, s, getId(s));

        int V = nextId; // Total number of unique strings (nodes in our graph)

        // 2. Build the Graph and initialize Floyd-Warshall Matrix
        const long long INF = 1e18; 
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        for (int i = 0; i < V; i++) dist[i][i] = 0;

        for (size_t i = 0; i < original.size(); ++i) {
            int u = strToId[original[i]];
            int v = strToId[changed[i]];
            // Handle multiple rules for the same pair by keeping the minimum cost
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 3. Run Floyd-Warshall to find All-Pairs Shortest Paths
        // This gives the min cost to convert any valid substring A to substring B
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < V; ++j) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // 4. Dynamic Programming to solve for source -> target
        int n = source.length();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue; // If current prefix is impossible, skip

            // Case A: Characters match exactly, cost is 0 to move to next char
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Case B: Try to convert a substring starting at i
            // We traverse the Trie with both source and target simultaneously
            TrieNode* nodeS = root;
            TrieNode* nodeT = root;
            
            for (int j = i; j < n; ++j) {
                int charS = source[j] - 'a';
                int charT = target[j] - 'a';

                // If either substring doesn't exist in our known rules, stop
                if (!nodeS->children[charS] || !nodeT->children[charT]) {
                    break; 
                }

                nodeS = nodeS->children[charS];
                nodeT = nodeT->children[charT];

                // If both current substrings map to valid IDs, check if a conversion path exists
                if (nodeS->id != -1 && nodeT->id != -1) {
                    long long conversionCost = dist[nodeS->id][nodeT->id];
                    if (conversionCost != INF) {
                        dp[j + 1] = min(dp[j + 1], dp[i] + conversionCost);
                    }
                }
            }
        }

        return (dp[n] == INF) ? -1 : dp[n];
    }
};