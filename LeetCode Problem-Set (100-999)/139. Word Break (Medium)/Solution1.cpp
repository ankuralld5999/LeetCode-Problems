// Problem: https://leetcode.com/problems/word-break/
// Author: github.com/ankuralld5999
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict), end(dict));
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < i && !dp[i]; ++j) {
                dp[i] = dp[j] && st.count(s.substr(j, i - j));
            }
        }
        return dp[N];
    }
};


//Minor optimization which won't check substrings whose lengths haven't shown up in the dictionary.

// Problem: https://leetcode.com/problems/word-break/
// Author: github.com/ankuralld5999
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict), end(dict));
        int N = s.size(), minLen = INT_MAX, maxLen = 0;
        for (auto &w : dict) {
            minLen = min(minLen, (int)w.size());
            maxLen = max(maxLen, (int)w.size());
        }
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int len = minLen; len <= maxLen && i - len >= 0 && !dp[i]; ++len) {
                dp[i] = dp[i - len] && st.count(s.substr(i - len, len));
            }
        }
        return dp[N];
    }
};
