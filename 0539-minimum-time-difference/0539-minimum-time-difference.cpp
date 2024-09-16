class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (int x = 0; x < timePoints.size(); x++) {
            int index = timePoints[x].find(':');
            string hours = timePoints[x].substr(0, index);
            string minute = timePoints[x].substr(index + 1);
            int m = stoi(hours) * 60;
            m += stoi(minute);
            minutes.push_back(m);
        }
        int minValue = INT_MAX;
        sort(minutes.begin(), minutes.end());
        for (int x = 0; x < minutes.size() - 1; x++) {
            for (int y = x + 1; y < minutes.size(); y++) {
                minValue = min(minValue, minutes[y] - minutes[x]);
                minValue =
                    min(minValue, 24 * 60 - (minutes[y] - minutes[x]));
            }
        }
        return minValue;
    }
};