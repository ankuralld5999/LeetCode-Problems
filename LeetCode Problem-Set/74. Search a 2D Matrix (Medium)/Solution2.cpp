// Problem: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/ankuralld5999
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int M = A.size(), N = A[0].size(), L = 0, R = M * N - 1;
        while (L <= R) {
            int mid = (L + R) / 2, val = A[mid / N][mid % N];
            if (val == target) return true;
            if (val < target) L = mid + 1;
            else R = mid - 1;
        }
        return false;
    }
};
