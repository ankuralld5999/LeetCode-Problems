// Problem: https://leetcode.com/problems/search-insert-position/
// Author: github.com/ankuralld5999
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        if(start == end){
            if(nums[start]==target)
                return start;
            else 
                return nums[start] < target ? start+1 : start;
        }else if(start > end)
            return start;
        return 0;
    }
};
