// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author: github.com/ankuralld5999
// Time: average O(N), worst O(logN)
// Space: O(1)
class Solution {
public:
    int findMin(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] > A[R]) L = M + 1;
            else if (A[M] < A[R]) R = M;
            else --R; // since `A[L]` might be the answer and `A[M]` is the same as `A[R]`, it's safe to --R.
        }
        return A[L];
    }
};
