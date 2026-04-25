class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> pos(n);
        
  
        for (int i = 0; i < n; ++i) {
            long long x = points[i][0];
            long long y = points[i][1];
            if (x == 0) pos[i] = y;
            else if (y == side) pos[i] = side + x;
            else if (x == side) pos[i] = 3LL * side - y;
            else pos[i] = 4LL * side - x;
        }
        
  
        sort(pos.begin(), pos.end());
        
       
        vector<long long> arr = pos;
        for (int i = 0; i < n; ++i) {
            arr.push_back(pos[i] + 4LL * side);
        }
        
        long long low = 1, high = side;
        int ans = 0;
        
       
        auto isValid = [&](long long limit) {
            for (int i = 0; i < n; ++i) {
                int count = 1;
                long long current = arr[i];
                int idx = i;
                
                for (int j = 1; j < k; ++j) {
                    auto it = lower_bound(arr.begin() + idx + 1, arr.begin() + i + n, current + limit);
                    if (it == arr.begin() + i + n) break; 
                    
                    idx = distance(arr.begin(), it);
                    current = arr[idx];
                    count++;
                }
                
              
                if (count == k && (arr[i] + 4LL * side - current >= limit)) {
                    return true;
                }
            }
            return false;
        };
        
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isValid(mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};