class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int sz = A.size();
        int res = 0;
        for (int shiftX = -1 * sz + 1; shiftX < sz; shiftX++) {
            for (int shiftY = -1 * sz + 1; shiftY < sz; shiftY++) {
                int xAStart = max(0, shiftX), xBStart = max(0, -1 * shiftX);
                int xAEnd = min(sz, sz + shiftX), xBEnd = min(sz, sz - shiftX);
                int yAStart = max(0, shiftY), yBStart = max(0, -1 * shiftY);
                int yAEnd = min(sz, sz + shiftY), yBEnd = min(sz, sz - shiftY);
                int xA = xAStart, xB = xBStart, yA = yAStart, yB = yBStart;
                
                int count = 0;
                for (int iA = xAStart, iB = xBStart; iA < xAEnd; iA++, iB++) {
                    for (int jA = yAStart, jB = yBStart; jA < yAEnd; jA++, jB++) {
                        if (A[iA][jA] == B[iB][jB] && A[iA][jA] == 1) count++;
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
