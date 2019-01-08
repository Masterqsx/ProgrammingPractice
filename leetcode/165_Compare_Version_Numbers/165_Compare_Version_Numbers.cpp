class Solution {
public:
    vector<int> split(string version) {
        vector<int> res = vector<int>();
        stringstream ss = stringstream(version);
        string temp;
        while (getline(ss, temp, '.')) {
            res.push_back(stoi(temp));
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<int> digits1 = split(version1);
        vector<int> digits2 = split(version2);
        for (int i = 0; i < max(digits1.size(), digits2.size()); i++) {
            int i1 = 0, i2 = 0;
            if (i < digits1.size()) i1 = digits1[i];
            if (i < digits2.size()) i2 = digits2[i];
            if (i1 > i2) return 1;
            else if (i1 < i2) return -1;
        }
        return 0;
    }
};
