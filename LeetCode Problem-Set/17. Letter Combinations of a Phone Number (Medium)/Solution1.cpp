// Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: github.com/ankuralld5999
// Time: O(4^N)
// Space: O(N)
class Solution {
const vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backTracking(vector<string> &ans, string &cur, int flag, string &digits) {
        if(flag == digits.size()) ans.push_back(cur);
        if(flag < digits.size()) {
            for(auto c:map[digits[flag] - '2']) {
                cur[flag] = c;
                backTracking(ans, cur, flag + 1, digits);
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) return result;
        string cur(digits.size(), '0');
        backTracking(result, cur, 0, digits);
        return result;
    }      
};
