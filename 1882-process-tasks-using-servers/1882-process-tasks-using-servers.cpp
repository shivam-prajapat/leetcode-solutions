class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> busy_servers;

        int n = servers.size();
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        int m = tasks.size();
        vector<int> ans(m);
        long long current_time = 0;

        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            if (free_servers.empty()) {
                current_time = max(current_time, busy_servers.top().first);
            }
            
            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                free_servers.push(busy_servers.top().second);
                busy_servers.pop();
            }
            
            auto [weight, idx] = free_servers.top();
            free_servers.pop();
            
            ans[j] = idx;
            busy_servers.push({current_time + tasks[j], {weight, idx}});
        }
        
        return ans;
    }
};