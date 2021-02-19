// Problem: https://leetcode.com/problems/subsets/
// Author: github.com/ankuralld5999
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int start, int len, vector<int> &s) {
        if (s.size() == len) {
            ans.push_back(s);
            return;
        }
        for (int i = start; i <= A.size() - len + s.size(); ++i) {
            s.push_back(A[i]);
            dfs(A, i + 1, len, s);
            s.pop_back(); // backtrack
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> s;
        for (int len = 0; len <= A.size(); ++len) dfs(A, 0, len, s);
        return ans;
    }
};
