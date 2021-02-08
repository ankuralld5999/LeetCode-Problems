// Problem: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        if(v[0][0]==1)
            return 0;
        int m = v.size();
        int n = v[0].size();
        int dp[m][n];
        bool flag = false;
        for(int i=0; i<n; i++){
            if(flag || v[0][i]==1){
                flag = true;
                dp[0][i] = 0;
            }
            else
                dp[0][i] = 1;
        }
        flag = false;
        for(int i=0; i<m; i++){
            if(flag || v[i][0]==1){
                flag = true;
                dp[i][0] = 0;
            }
            else
                dp[i][0] = 1;
        }
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                if(v[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        return dp[m-1][n-1];
    }
};
