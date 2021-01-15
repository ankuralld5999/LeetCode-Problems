# [17. Letter Combinations of a Phone Number (Medium)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

<p>Given a string containing digits from <code>2-9</code> inclusive, return all possible letter combinations that the number could represent.</p>

<p>A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.</p>

<p><img src="http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png"></p>

<p><strong>Example:</strong></p>

<pre><strong>Input: </strong>"23"
<strong>Output:</strong> ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
</pre>

<p><strong>Note:</strong></p>

<p>Although the above answer is in lexicographical order, your answer could be in any order you want.</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Generate Parentheses (Medium)](https://leetcode.com/problems/generate-parentheses/)
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)
* [Binary Watch (Easy)](https://leetcode.com/problems/binary-watch/)

## Solution 1. DFS

```cpp
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
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: github.com/ankuralld5999
// Time: O(4^N * N)
// Space: O(4^N * N)
class Solution {
private:
    vector<string> M{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans{""};
        for (char c : digits) {
            vector<string> next;
            string m = M[c - '2'];
            for (string s : ans) {
                for (char c : m) {
                    next.push_back(s + c);
                }
            }
            ans = next;
        }
        return ans;
    }
};
```
