class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

      
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        stack<int> st;
        for (int curr : indices) {
            if (directions[curr] == 'R') {
                st.push(curr);
            } else {
              
                while (!st.empty() && healths[curr] > 0) {
                    int top = st.top();
                    
                    if (healths[curr] > healths[top]) {
                      
                        healths[curr] -= 1;
                        healths[top] = 0;
                        st.pop();
                    } else if (healths[curr] < healths[top]) {
                        
                        healths[top] -= 1;
                        healths[curr] = 0;
                       
                    } else {
                     
                        healths[curr] = 0;
                        healths[top] = 0;
                        st.pop();
                    }
                }
            }
        }

      
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};