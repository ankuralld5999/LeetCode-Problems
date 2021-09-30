// Problem: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/ankuralld5999
// Time: O(S)
// Space: O(S)
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for (int i = s.size() - 1; i >= 0;) {
            while (i >= 0 && s[i] == ' ') --i;
            if (i < 0) break;
            if (ans.size()) ans += ' ';
            int j = i;
            while (j >= 0 && s[j] != ' ') --j;
            for (int k = j + 1; k <= i; ++k) ans += s[k];
            i = j;
        }
        return ans;
    }
};
