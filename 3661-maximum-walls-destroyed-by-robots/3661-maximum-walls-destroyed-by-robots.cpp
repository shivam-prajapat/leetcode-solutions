


class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        
        struct Robot {
            int pos;
            int dist;
            bool operator<(const Robot& other) const {
                return pos < other.pos;
            }
        };
        
        vector<Robot> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {robots[i], distance[i]};
        }
        
       
        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());
        
        int dp0 = 0, dp1 = 0;
        
        for (int i = 0; i < n; i++) {
            int next_dp0 = 0, next_dp1 = 0;
            
            
            int left_bound = arr[i].pos - arr[i].dist;
            if (i > 0) {
              
                left_bound = max(left_bound, arr[i-1].pos + 1);
            }
            
            int l0 = lower_bound(walls.begin(), walls.end(), left_bound) - walls.begin();
            int r0 = lower_bound(walls.begin(), walls.end(), arr[i].pos + 1) - walls.begin();
            int count0 = max(0, r0 - l0);
            int ans0 = dp0 + count0; 
            
          
            for (int j = 0; j < 2; j++) {
                
                if (i == n - 1 && j == 0) continue; 
                
              
                int right_bound = arr[i].pos + arr[i].dist;
                if (i + 1 < n) {
                    if (j == 0) {
                      
                        right_bound = min(right_bound, arr[i+1].pos - arr[i+1].dist - 1);
                    } else {
                       
                        right_bound = min(right_bound, arr[i+1].pos - 1);
                    }
                }
                
                int l1 = lower_bound(walls.begin(), walls.end(), arr[i].pos) - walls.begin();
                int r1 = lower_bound(walls.begin(), walls.end(), right_bound + 1) - walls.begin();
                int count1 = max(0, r1 - l1);
                int ans1 = dp1 + count1;
                
              
                if (j == 0) {
                    next_dp0 = max(ans0, ans1);
                } else {
                    next_dp1 = max(ans0, ans1);
                }
            }
            
           
            dp0 = next_dp0;
            dp1 = next_dp1;
        }
        
      
        return dp1;
    }
};