class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_finish_land = INT_MAX;
        for (int i = 0; i < landStartTime.size(); ++i) {
            min_finish_land = min(min_finish_land, landStartTime[i] + landDuration[i]);
        }
        
        int min_finish_water = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); ++j) {
            min_finish_water = min(min_finish_water, waterStartTime[j] + waterDuration[j]);
        }
        
        int earliest_finish = INT_MAX;
        
        for (int j = 0; j < waterStartTime.size(); ++j) {
            int current_finish = max(min_finish_land, waterStartTime[j]) + waterDuration[j];
            earliest_finish = min(earliest_finish, current_finish);
        }
        
        for (int i = 0; i < landStartTime.size(); ++i) {
            int current_finish = max(min_finish_water, landStartTime[i]) + landDuration[i];
            earliest_finish = min(earliest_finish, current_finish);
        }
        
        return earliest_finish;
    }
};