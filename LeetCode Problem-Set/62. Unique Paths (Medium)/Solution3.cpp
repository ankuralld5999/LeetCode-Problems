// Problem: https://leetcode.com/problems/unique-paths/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for (int i = 1; i <= n - 1; ++i) ans = ans * (m - 1 + i) / i;
        return ans;
    }
};
