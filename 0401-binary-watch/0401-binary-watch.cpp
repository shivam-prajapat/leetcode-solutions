

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        // Iterate through all possible hours (0-11)
        for (int h = 0; h < 12; h++) {
            // Iterate through all possible minutes (0-59)
            for (int m = 0; m < 60; m++) {
                
                // Count the total number of bits set in hour and minute
                // bitset<4>(h).count() counts bits for hours
                // bitset<6>(m).count() counts bits for minutes
                if (bitset<4>(h).count() + bitset<6>(m).count() == turnedOn) {
                    
                    // Format the time string
                    string time = to_string(h) + ":";
                    
                    // Add leading zero for minutes if less than 10
                    if (m < 10) {
                        time += "0";
                    }
                    time += to_string(m);
                    
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};