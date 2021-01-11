// Problem: https://leetcode.com/problems/regular-expression-matching/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isMatch(string str, string patt) {
        int s = str.size();
        int p = patt.size();
        bool dp[s+1][p+1];
        for(int i=0; i<=s; i++)
            for(int j=0; j<=p; j++)
                dp[i][j] = false;
        
        dp[0][0] = true;
        for(int i=1; i<=p; i++)
            if(patt[i-1] == '*' && dp[0][i-2])
                dp[0][i] = true;
        for(int i=1; i<=s; i++){
            for(int j=1; j<=p; j++){
                if(str[i-1]==patt[j-1] || patt[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else if(patt[j-1] == '*'){
                    if(patt[j-2] == str[i-1] || patt[j-2]=='.')
                        dp[i][j] = (dp[i][j-2] || dp[i-1][j]);
                    else
                        dp[i][j] = dp[i][j-2];
                }
            }
        }
        return dp[s][p];
    }
};
