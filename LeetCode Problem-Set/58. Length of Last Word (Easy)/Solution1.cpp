// Problem: https://leetcode.com/problems/length-of-last-word/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while(i>=0 && s[i] == ' ')
            i--;
        int j = i;
        while(i>=0 && s[i]!=' ')
            i--;
        return j-i;
    }
};
