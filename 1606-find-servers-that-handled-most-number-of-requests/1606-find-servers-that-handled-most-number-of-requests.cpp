class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> busy;
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long curr_time = arrival[i];
            
            while (!busy.empty() && busy.top().first <= curr_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) {
                continue;
            }
            
            int target_idx = i % k;
            auto it = available.lower_bound(target_idx);
            if (it == available.end()) {
                it = available.begin();
            }
            
            int server = *it;
            count[server]++;
            busy.push({curr_time + load[i], server});
            available.erase(it);
        }
        
        int max_req = 0;
        for (int c : count) {
            max_req = max(max_req, c);
        }
        
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_req) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};