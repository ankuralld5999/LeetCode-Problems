// Problem: https://leetcode.com/problems/edit-distance
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        if (A.empty() || B.empty()) return max(A.size(), B.size());
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) dp[i + 1][0] = i + 1;
        for (int j = 0; j < N; ++j) dp[0][j + 1] = j + 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min({ dp[i][j], dp[i][j + 1], dp[i + 1][j] });
            }
        }
        return dp[M][N];
    }
};


//Or in another form.

// Problem: https://leetcode.com/problems/edit-distance
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
        return dp[M][N];
    }
};
