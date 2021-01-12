// Problem: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
class Solution {
public:
    int maxArea(vector<int>& A) {
        int ans = 0, L = 0, R = A.size() - 1;
        while (L < R) {
            ans = max(ans, (R - L) * min(A[L], A[R]));
            if (A[L] < A[R]) ++L; // Move the smaller edge
            else --R;
        }
        return ans;
    }
};
