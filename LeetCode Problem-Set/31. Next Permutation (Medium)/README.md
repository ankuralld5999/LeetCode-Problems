# [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)

<p>Implement <strong>next permutation</strong>, which rearranges numbers into the lexicographically next greater permutation of numbers.</p>

<p>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a></strong> and use only constant&nbsp;extra memory.</p>

<p>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.</p>

<p><code>1,2,3</code> â†’ <code>1,3,2</code><br>
<code>3,2,1</code> â†’ <code>1,2,3</code><br>
<code>1,1,5</code> â†’ <code>1,5,1</code></p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/next-permutation
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int len, n;
    string s;
    bool rec(int i, unordered_map<string, int> &m, int cnt) {
        if (cnt == n) return true;
        int &v = m[s.substr(i, len)];
        if (v) {
            v--;
            bool ret = rec(i + len, m, cnt + 1);
            v++;
            return ret;
        }
        return false;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return {};
        this->s = s;
        len = words[0].size();
        n = words.size();
        unordered_map<string, int> m;
        for (string word : words) ++m[word];
        int end = s.size() - n * len;
        vector<int> v;
        for (int i = 0; i <= end; ++i) {
            if (rec(i, m, 0)) v.push_back(i);
        }
        return v;
    }
};
```
