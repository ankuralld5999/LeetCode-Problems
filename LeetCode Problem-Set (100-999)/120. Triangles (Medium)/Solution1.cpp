// Problem: https://leetcode.com/problems/triangle/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n + 1);
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};
