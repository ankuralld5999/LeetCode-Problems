// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0 ; i<nums.size(); i++){
            if(nums[i] == target)
                return i;
        }
        return int(-1);
    }
};
