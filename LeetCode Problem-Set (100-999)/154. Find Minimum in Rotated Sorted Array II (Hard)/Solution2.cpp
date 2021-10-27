// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author: github.com/ankuralld5999
// Time: average O(N), worst O(N)
// Space: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        
        for(int x : nums)
            ans = min(ans, x);
        
        return ans;
    }
};
