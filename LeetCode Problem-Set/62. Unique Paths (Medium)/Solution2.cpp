// Problem: https://leetcode.com/problems/unique-paths/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) dp[j] += dp[j + 1];
        }
        return dp[0];
    }
};
