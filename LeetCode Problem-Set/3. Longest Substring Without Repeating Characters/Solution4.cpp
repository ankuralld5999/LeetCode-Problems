// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128);
        int i = 0, j = 0, ans = 0;
        for (; j < s.size(); ++j) {
            cnt[s[j]]++;
            while (cnt[s[j]] > 1) cnt[s[i++]]--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
