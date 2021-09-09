// Problem: https://leetcode.com/problems/single-number-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int n : nums) {
            one = (one ^ n) & ~two;
            two = (two ^ n) & ~one;
        }
        return one;
    }
};
