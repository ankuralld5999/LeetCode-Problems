// Problem: https://leetcode.com/problems/subsets/
// Author: github.com/ankuralld5999
// Time: O(N * 2^N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) {
        int N = 1 << A.size();
        vector<vector<int>> ans(N);
        for (int i = 0; i < A.size(); ++i) { // For each numbers in A
            for (int j = 0; j < N; ++j) { // check if it is in the jth subset in the output
                if (j >> i & 1) ans[j].push_back(A[i]);
            }
        }
        return ans;
    }
};
