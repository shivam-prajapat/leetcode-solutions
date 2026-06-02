class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_finish_time = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int finish_land = landStartTime[i] + landDuration[i];
                int start_water = max(finish_land, waterStartTime[j]);
                int finish1 = start_water + waterDuration[j];
                
                int finish_water = waterStartTime[j] + waterDuration[j];
                int start_land = max(finish_water, landStartTime[i]);
                int finish2 = start_land + landDuration[i];
                
                min_finish_time = min({min_finish_time, finish1, finish2});
            }
        }
        
        return min_finish_time;
    }
};