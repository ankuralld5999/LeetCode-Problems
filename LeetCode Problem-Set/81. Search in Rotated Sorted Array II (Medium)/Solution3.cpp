// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/ankuralld5999
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return true;
            if (A[0] > A[M]) {
                if (target > A[M]) {
                    if (target <= A.back()) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            } else if (A[0] < A[M]) {
                if (target > A[M]) L = M + 1;
                else {
                    if (target >= A[0]) R = M - 1; 
                    else L = M + 1;
                }
            } else if (A[L] == target) return true;
            else ++L;
        }
        return false;
    }
};
