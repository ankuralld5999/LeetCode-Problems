// Problem: https://leetcode.com/problems/sort-colors/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, g = 0, b = 0;
        for (int n : nums) {
            if (n == 0) {
                nums[b++] = 2;
                nums[g++] = 1;
                nums[r++] = 0;
            } else if (n == 1) {
                nums[b++] = 2;
                nums[g++] = 1;
            } else nums[b++] = 2;
        }
    }
};
