// Problem: https://leetcode.com/problems/subsets/
// Author: github.com/ankuralld5999
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int i, vector<int> &s) {
        if (i == A.size()) {
            ans.push_back(s);
            return;
        }
        s.push_back(A[i]); // Pick A[i]
        dfs(A, i + 1, s);
        s.pop_back(); // Skip A[i]
        dfs(A, i + 1, s);
    }
public:
    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> s;
        dfs(A, 0, s);
        return ans;
    }
};
