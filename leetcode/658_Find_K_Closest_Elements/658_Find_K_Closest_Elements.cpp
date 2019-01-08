class Solution {
public:
    int bs(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int bound = bs(arr, x);
        int l = 0, r = 0;
        vector<int> res;
        if (arr[bound] == x) {
            l = bound - 1;
            r = bound + 1;
            k--;
            res.push_back(x);
        }
        else if (arr[bound] > x) {
            r = bound;
            l = bound - 1;
        }
        else {
            l = bound;
            r = bound + 1;
        }
        while (k > 0) {
            int tl = (l >= 0 && l < arr.size())? arr[l] : INT_MIN + 20000;
            int tr = (r >= 0 && r < arr.size())? arr[r] : INT_MAX - 20000;
            if (abs(tl - x) > abs(tr - x)) {
                res.push_back(tr);
                r++;
            }
            else {
                res.push_back(tl);
                l--;
            }
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
