// Problem: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/ankuralld5999
// Time: O(S)
// Space: O(S)
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word, ans;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            if (ans.size()) ans += ' '; 
            ans += word;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
