// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/ankuralld5999
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] > A[R]) {
                if (target > A[M]) L = M + 1;
                else if (target >= A[L]) R = M - 1;
                else L = M + 1;
            } else {
                if (target > A[M]) {
                    if (target <= A[R]) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            }
        }
        return -1;
    }
};


//We can simplify it by combining the cases.


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
            if ((A[M] > A[R] && (target > A[M] || target < A[L]))
               || (A[M] <= A[R] && (target > A[M] && target <= A[R]))) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};
