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
            if (ans.size()) word += " ";
            ans = word + ans;
        }
        return ans;
    }
};
