// Problem: https://leetcode.com/problems/unique-binary-search-trees
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};
