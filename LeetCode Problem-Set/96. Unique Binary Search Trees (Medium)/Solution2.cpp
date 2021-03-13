// Problem: https://leetcode.com/problems/unique-binary-search-trees
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(N)
class Solution {
    vector<int> memo;
    int dp(int n) {
        if (memo[n]) return memo[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += dp(i) * dp(n - i - 1);
        return memo[n] = ans;
    }
public:
    int numTrees(int n) {
        memo.assign(n + 1, 0);
        memo[0] = 1;
        return dp(n);
    }
};
