class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
       
        unordered_set<long long> obsSet;
        for (const auto& obs : obstacles) {
            
            obsSet.insert(obs[0] * 60001LL + obs[1]);
        }

       
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0; 

        int x = 0, y = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
              
                dir = (dir + 1) % 4; 
            } else if (cmd == -2) {
                
                dir = (dir + 3) % 4; 
            } else {
             
                for (int step = 0; step < cmd; ++step) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                
                    if (obsSet.count(nx * 60001LL + ny)) {
                        break;
                    }

                   
                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};