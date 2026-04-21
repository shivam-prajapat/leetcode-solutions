

class Solution {
public:
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
       
        iota(parent.begin(), parent.end(), 0);
        
   
        for (const auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
       
        unordered_map<int, unordered_map<int, int>> componentCounts;
        
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            componentCounts[root][source[i]]++;
        }
        
        int hammingDistance = 0;
        
        // 3. Calculate the Hamming Distance
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            // If the target element exists in the corresponding source component
            if (componentCounts[root][target[i]] > 0) {
                componentCounts[root][target[i]]--; // Match found, consume one count
            } else {
                hammingDistance++; // No match available, increases Hamming distance
            }
        }
        
        return hammingDistance;
    }
};