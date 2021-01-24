# [35. Search Insert Position (Easy)](https://leetcode.com/problems/search-insert-position/)

<p>Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.</p>

<p>You may assume no duplicates in the array.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,3,5,6], 5
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [1,3,5,6], 2
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> [1,3,5,6], 7
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> [1,3,5,6], 0
<strong>Output:</strong> 0
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [First Bad Version (Easy)](https://leetcode.com/problems/first-bad-version/)

## Solution 1. Binary Search

```cpp
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
```
