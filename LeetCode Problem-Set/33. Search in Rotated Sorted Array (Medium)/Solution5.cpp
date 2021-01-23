// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/ankuralld5999
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[0] <= A[M]) {
                if (A[M] < target || target < A[0]) L = M + 1;
                else R = M - 1;
            } else {
                if (target < A[M] || target >= A[0]) R = M - 1;
                else L = M + 1;
            }
        }
        return -1;
    }
};


//Or simplify the code by combining the cases:


// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/ankuralld5999
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if ((A[0] <= A[M] && (A[M] < target || target < A[0]))
               || (A[0] > A[M] && target > A[M] && target < A[0])) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
