class Solution {
public:
    vector<int> ma(vector<int>& lhs, vector<int>& rhs) {
        int i;
        for (i=0;i<min(lhs.size(), rhs.size());i++) {
            if (lhs[i] > rhs[i]) return lhs;
            else if (lhs[i] < rhs[i]) return rhs;
        }
        if (i == lhs.size()) return rhs;
        else return lhs;
    }
    bool ma(vector<int>& lhs, vector<int>& rhs, int hl, int hr) {
        int i;
        for (i=0;i<min(lhs.size()-hl, rhs.size()-hr);i++) {
            if (lhs[i+hl] > rhs[i+hr]) return true;
            else if (lhs[i+hl] < rhs[i+hr]) return false;
        }
        if (i == lhs.size()-hl) return false;
        else return true;
    }
    void getVector(vector<int>& nums, vector<int>& res, int k) {
        if (k == 0) return;
        if (nums.size() <= k) res = nums;
        else {
            res = vector<int>(nums.begin(), nums.begin()+k);
            for (int i=k;i<nums.size();i++) {
                int j = 0;
                for (j=0;j<k-1;j++) {
                    if (res[j] < res[j+1]) break;
                }
                if (j < k-1 || j == k-1 && nums[i] > res[j]) {
                    res.erase(res.begin()+j);
                    res.push_back(nums[i]);
                }
            }
        }
    }
    void mergeVector(vector<int>& nums1, vector<int>& nums2, vector<int>& res, int k) {
        unsigned int h1 = 0, h2 = 0;
        for (int i=0;i<k;i++) {
            if ((nums2.size() <= h2) || (h1 < nums1.size() && nums1[h1] > nums2[h2])) {
                res.push_back(nums1[h1]);
                h1++;
            }
            else if ((nums1.size() <= h1) || (h2 < nums2.size() && nums1[h1] < nums2[h2])) {
                res.push_back(nums2[h2]);
                h2++;
            }
            else if (h1 < nums1.size() && h2 < nums2.size() && nums1[h1] == nums2[h2]) {//when have same number, we need look at the next different number
                if (ma(nums1, nums2, h1, h2)) res.push_back(nums1[h1++]);
                else res.push_back(nums2[h2++]);
            }
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> max_nb;
        for (int i=max(0, k-(int)nums2.size());i<=min(k, (int)nums1.size());i++) {
            vector<int> res1, res2, res;
            getVector(nums1, res1, i);
            getVector(nums2, res2, k-i);
            mergeVector(res1, res2, res, k);
            max_nb = ma(max_nb, res);
        }
        return max_nb;
    }
};
