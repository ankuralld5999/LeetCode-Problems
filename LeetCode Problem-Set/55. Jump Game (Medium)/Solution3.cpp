// Problem: https://leetcode.com/problems/jump-game/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& A) {
        int last = 0;
        for (int i = 0; i <= last; ++i) {
            last = max(last, i + A[i]);
            if (last >= A.size() - 1) return true;
        }
        return false;
    }
};
