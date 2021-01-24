// Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
// Author: github.com/ankuralld5999
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        while(start <= end){
            mid = start + (end-start)/2;
            if(nums[mid] == target)
                break;
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        if(start > end){
            return {-1,-1};
        }
        while(start <=mid){
            if(nums[start]==target)
                break;
            start++;
        }
        while(end>=mid){
            if(nums[end]==target)
                break;
            end--;
        }
        return {start,end};
    }
};
