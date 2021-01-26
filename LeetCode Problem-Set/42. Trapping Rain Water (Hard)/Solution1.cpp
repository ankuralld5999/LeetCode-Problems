// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> left(N, 0), right(N, 0);
        for (int i = 1; i < N; ++i) 
            left[i] = max(left[i - 1], A[i - 1]);
        for (int i = N - 2; i >= 0; --i) 
            right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 1; i < N - 1; ++i) 
            ans += max(0, min(left[i], right[i]) - A[i]);
        return ans;
    }
};

//Or

// Problem: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0, mx = 0, left = 0;
        vector<int> right(N);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 0; i < N; ++i) {
            ans += max(0, min(left, right[i]) - A[i]);
            left = max(left, A[i]);
        }
        return ans;
    }
};
