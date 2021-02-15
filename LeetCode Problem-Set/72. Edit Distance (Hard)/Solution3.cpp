// Problem: https://leetcode.com/problems/edit-distance
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        if (M < N) {
            swap(word1, word2);
            swap(M, N);
        }
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) dp[i] = i;
        for (int i = 1; i <= M; ++i) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j) {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1]) dp[j] = pre;
                else dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[N];
    }
};


//Or in another form

// Problem: https://leetcode.com/problems/edit-distance
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(A, B), swap(M, N); 
        vector<int> dp(N + 1, INT_MAX);
        for (int i = 0; i <= M; ++i) {
            int prev;
            for (int j = 0; j <= N; ++j) {
                int cur = dp[j];
                if (i == 0 || j == 0) dp[j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[j] = prev;
                else dp[j] = 1 + min({ dp[j], dp[j - 1], prev });
                prev = cur;
            }
        }
        return dp[N];
    }
};
