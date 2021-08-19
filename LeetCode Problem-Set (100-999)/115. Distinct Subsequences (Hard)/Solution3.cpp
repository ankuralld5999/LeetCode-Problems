// Problem: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/ankuralld5999
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        vector<LL> dp(t.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size(); j > 0; --j) {
                if (s[i] == t[j - 1]) dp[j] += dp[j - 1];
            }
        }
        return dp[t.size()];
    }
};
Or in another form:

// Problem: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/ankuralld5999
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<LL> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            int prev;
            for (int j = N; j >= 0; --j) {
                int cur = dp[j];
                if (i == M || j == N) dp[j] = j == N;
                else if (s[i] == t[j]) dp[j] += prev;
                prev = cur;
            }
        }
        return dp[0];
    }
};
Or:

// Problem: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/ankuralld5999
// Time: O(ST)
// Space: O(T)
class Solution {
    typedef long long LL;
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<LL> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            for (int j = 0; j <= N; ++j) {
                if (i == M || j == N) dp[j] = j == N;
                else if (s[i] == t[j]) dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};
