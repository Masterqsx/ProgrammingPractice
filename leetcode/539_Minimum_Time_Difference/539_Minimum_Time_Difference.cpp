class Solution {
public:
    int transform(string& timePoint) {
        return stoi(timePoint.substr(timePoint.find(':') + 1)) + 60 * stoi(timePoint.substr(0, timePoint.find(':')));
    }
    int findMinDifference(vector<string>& timePoints) {
        int timePointsBucket[1440];
        memset(timePointsBucket, 0, 1440 * sizeof(*timePointsBucket));
        for (string str : timePoints) {
            timePointsBucket[transform(str)]++;
        }
        vector<int> timeRes;
        for (int i = 0; i < 1440; i++) {
            if (timePointsBucket[i] > 1) return 0;
            if (timePointsBucket[i] > 0) timeRes.push_back(i);
        }
        int res = 1440;
        for (int i = 0; i < timeRes.size(); i++) {
            if (i > 0) res = min(res, timeRes[i] - timeRes[i - 1]);
            if (i < timeRes.size() - 1) res = min(res, timeRes[i + 1] - timeRes[i]);
            if (i == 0) res = min(res, 1440 - timeRes[i] + timeRes[1]);
            else res = min(res, 1440 - timeRes[i] + timeRes[0]);
        }
        return res;
    }
};
