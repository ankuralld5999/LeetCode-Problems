// Problem: https://leetcode.com/problems/climbing-stairs/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int ans = 1, prev = 1;
        while (--n) {
            ans += prev;
            prev = ans - prev;
        }
        return ans;
    }
};
