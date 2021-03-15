// Problem: https://leetcode.com/problems/interleaving-string/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m != s3.size())
            return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                int l = i + j -1;
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    if(s3[l] == s2[j-1]){
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else if(j == 0){
                    if(s1[i-1] == s3[l]){
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else{
                    dp[i][j] = (s1[i-1] == s3[l] ? dp[i-1][j] : false) || 
                        (s2[j-1] == s3[l] ? dp[i][j-1] : false);
                }
            }
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][m];
    }
};
