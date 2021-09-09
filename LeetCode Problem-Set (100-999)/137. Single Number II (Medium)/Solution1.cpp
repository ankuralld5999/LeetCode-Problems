// Problem: https://leetcode.com/problems/single-number-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (unsigned n : nums) {
                cnt = (cnt + ((n >> i) & 1)) % 3;
            }
            ans |= cnt << i;
        }
        return ans;
    }
};
