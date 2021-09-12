// Problem: https://leetcode.com/problems/word-break/
// Author: github.com/ankuralld5999
// Time: O(S^3)
// Space: O(S + W)
class Solution {
    unordered_set<string> st;
    vector<int> m;
    bool dp(string &s, int i) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        m[i] = 0;
        for (int j = i + 1; j <= s.size() && m[i] != 1; ++j) {
            if (!dp(s, j) || st.count(s.substr(i, j - i)) == 0) continue;
            m[i] = 1;
        }
        return m[i];
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        m.assign(s.size(), -1);
        st = { begin(dict), end(dict) };
        return dp(s, 0);
    }
};


//Minor optimization which won't check substrings whose lengths haven't shown up in the dictionary.

// Problem: https://leetcode.com/problems/word-break/
// Author: github.com/ankuralld5999
// Time: O(S^3)
// Space: O(S + W)
class Solution {
    unordered_set<string> st;
    int minLen = INT_MAX, maxLen = 0;
    vector<int> m;
    bool dp(string &s, int i) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        m[i] = 0;
        for (int len = minLen; len <= maxLen && i + len <= s.size() && m[i] != 1; ++len) {
            if (!dp(s, i + len) || st.count(s.substr(i, len)) == 0) continue;
            m[i] = 1;
        }
        return m[i];
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        m.assign(s.size(), -1);
        for (auto &w : dict) {
            st.insert(w);
            maxLen = max(maxLen, (int)w.size());
            minLen = min(minLen, (int)w.size());
        }
        return dp(s, 0);
    }
};
