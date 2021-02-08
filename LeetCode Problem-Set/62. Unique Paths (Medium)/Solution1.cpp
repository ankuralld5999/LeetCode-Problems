// Problem: https://leetcode.com/problems/unique-paths/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(i==0 || j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        return dp[m-1][n-1];
    }
};
