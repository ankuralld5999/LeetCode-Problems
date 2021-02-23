// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == target)
                return true;
        
        return false;
    }
};
