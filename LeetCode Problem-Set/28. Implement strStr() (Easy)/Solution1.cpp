// Problem: https://leetcode.com/problems/implement-strstr/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int strStr(string s1, string s2) {
        if(s1==s2 || s2.size()==0)
            return 0;
        if(s1.size() < s2.size())
            return -1;
        int n = s1.size(), m = s2.size(), i, j, k;
        for(i=0; i<=n-m; i++){
            if(s1[i]==s2[0]){
                j=i+1;
                k=1;
                while(s1[j]==s2[k] && k<m){
                    j++; k++;
                }
                if(k==m)
                    return i;
            }
        }
        return -1;
    }
};
