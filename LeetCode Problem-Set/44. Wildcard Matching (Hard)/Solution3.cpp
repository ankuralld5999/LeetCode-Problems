// Problem: https://leetcode.com/problems/wildcard-matching/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(1)
// Ref: https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution
class Solution { public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size(), star = -1, ss = 0, i = 0, j = 0;
        while (i < M) {
            if (p[j] == '?' || p[j] == s[i]) {
                ++i;
                ++j;
                continue;
            }
            if (p[j] == '*') {
                star = j++;
                ss = i;
                continue;
            }
            if (star != -1) {
                j = star + 1;
                i = ++ss;
                continue;
            }
            return false;
        }
        while (p[j] == '*') ++j;
        return j == N;
    }
};
