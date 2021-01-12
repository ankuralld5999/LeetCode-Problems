// Problem: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (!A[i]) continue;
            for (int j = i + 1 + ans / A[i]; j < N; ++j) {
                ans = max(ans, min(A[i], A[j]) * (j - i));
            }
        }
        return ans;
    }
};
