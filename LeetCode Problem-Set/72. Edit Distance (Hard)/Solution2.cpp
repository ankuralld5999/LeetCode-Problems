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
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) dp[0][i] = i;
        for (int i = 1; i <= M; ++i) {
            dp[i % 2][0] = i;
            for (int j = 1; j <= N; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = 1 + min(min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]), dp[(i - 1) % 2][j - 1]);
            }
        }
        return dp[M % 2][N];
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
        vector<vector<int>> dp(2, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) dp[i % 2][j] = i + j;
                else if (A[i - 1] == B[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = 1 + min({ dp[(i - 1) % 2][j], dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1] });
            }
        }
        return dp[M % 2][N];
    }
};
