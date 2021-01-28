// Problem: https://leetcode.com/problems/wildcard-matching/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isMatch(string s, string p) {
        string pattern = "";
        int writeIndex = 0;
        bool isFirst = true;
        for ( int i = 0 ; i < p.length(); i++) {
            if (p[i] == '*') {
                if (isFirst) {
                    pattern += p[i];
                    writeIndex++;
                    isFirst = false;
                }
            } else {
                pattern += p[i];
                writeIndex++;
                isFirst = true;
            }
        }
        int m = s.size();
        int n = pattern.size();
        bool dp[m+1][n+1];
        
        for(int i = 1; i<=m; i++)
            dp[i][0]=false;
        for(int i = 1; i<=n; i++)
            dp[0][i]=false;

        if (writeIndex > 0 && pattern[0] == '*') {
            dp[0][1] = true;
        }

        dp[0][0] = true;
        for(int i = 1; i<=m; i++){
            for(int j=1; j<=n; j++){
               if(s[i-1]==pattern[j-1] || pattern[j-1]=='?')
                   dp[i][j]=dp[i-1][j-1];
                else if(pattern[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};
