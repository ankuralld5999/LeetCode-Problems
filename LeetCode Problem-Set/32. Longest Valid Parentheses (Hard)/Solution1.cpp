// Problem: https://leetcode.com/problems/longest-valid-parentheses/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        int ans = 0;
        for(int i=0; i<s.size()-1 ;i++){
            int v = 0;
            for(int j=i; j<s.size(); j++){
                v += s[j]=='(' ? 1 : -1;
                if(v<0)
                    break;
                if(v==0)
                    ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
