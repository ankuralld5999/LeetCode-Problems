// Problem: https://leetcode.com/problems/implement-strstr/
// Author: github.com/ankuralld5999
// Time: O(M+N)
// Space: O(N)
class Solution {
    vector<int> getLps(string &s) {
        int N = s.size(), j = -1;
        vector<int> lps(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            while (j >= 0 && s[i - 1] != s[j]) j = lps[j];
            lps[i] = ++j;
        }
        return lps;
    }
public:
    int strStr(string s, string t) {
        if (t.empty()) return 0;
        int M = s.size(), N = t.size(), i = 0, j = 0;
        auto lps = getLps(t);
        while (i < M) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            if (j == N) return i - j;
            if (i < M && s[i] != t[j]) {
                if (j) j = lps[j];
                else ++i;
            }
        }
        return -1;
    }
};
