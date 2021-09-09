// Problem: https://leetcode.com/problems/single-number/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) ans ^= n;
        return ans;
    }
};
