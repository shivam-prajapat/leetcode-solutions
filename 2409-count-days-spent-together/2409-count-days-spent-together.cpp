class Solution {
    int dateToDays(const string& date) {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 1; i < month; ++i) {
            totalDays += daysInMonth[i];
        }
        totalDays += day;
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aArrive = dateToDays(arriveAlice);
        int aLeave = dateToDays(leaveAlice);
        int bArrive = dateToDays(arriveBob);
        int bLeave = dateToDays(leaveBob);
        
        int start = max(aArrive, bArrive);
        int end = min(aLeave, bLeave);
        
        return max(0, end - start + 1);
    }
};