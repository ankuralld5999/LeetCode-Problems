# [41. First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)

<p>Given an unsorted integer array, find the smallest missing&nbsp;positive integer.</p>

<p><strong>Example 1:</strong></p>

<pre>Input: [1,2,0]
Output: 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>Input: [3,4,-1,1]
Output: 2
</pre>

<p><strong>Example 3:</strong></p>

<pre>Input: [7,8,9,11,12]
Output: 1
</pre>

<p><strong>Note:</strong></p>

<p>Your algorithm should run in <em>O</em>(<em>n</em>) time and uses constant extra space.</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
* [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
* [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/first-missing-positive/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contains_one = false;
        for(int x: nums){
            if(x == 1){
                contains_one = true;
                break;
            }
        }
        if(!contains_one) return 1;
        
        int n = nums.size();
        if(n == 1) return 2;
        
        for(int i = 0; i < n; ++i)
            if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        
        for(int i = 0; i < n; ++i){
            int x = abs(nums[i]);
            if(nums[x-1] > 0) nums[x-1] *= -1;
        }
        
        for(int i = 0; i < n; ++i)
            if(nums[i] > 0) return i+1;
        
        return n+1;
    }
};
```
