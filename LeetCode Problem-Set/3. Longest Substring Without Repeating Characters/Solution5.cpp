// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128);
        int i = 0, j = 0, k = 0;
        for (; j < s.size(); ++j) {
            if (++cnt[s[j]] == 2) ++k;
            if (k >= 1) k -= --cnt[s[i++]] == 1;
        }
        return j - i;
    }
};
```
