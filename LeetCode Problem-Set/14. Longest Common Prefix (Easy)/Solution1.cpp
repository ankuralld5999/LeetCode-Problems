// Problem: https://leetcode.com/problems/3sum/
// Author: github.com/ankuralld5999
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string s = strs[0];
        int n = strs.size();
        int ans = s.size();
        for(int i=0; i<n ;i++){
            int count=0;
            for(int j=0; j<ans; j++){
                if(s[j]==strs[i][j])
                    count++;
                else{
                    ans = min(ans, count);
                    break;
                }
            }
        }
        string s1="";
        for(int i=0; i<ans; i++)
            s1+=s[i];
        return s1;
    }
};
