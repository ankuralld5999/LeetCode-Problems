# [15. 3Sum (Medium)](https://leetcode.com/problems/3sum/)

<p>Given an array <code>nums</code> of <em>n</em> integers, are there elements <em>a</em>, <em>b</em>, <em>c</em> in <code>nums</code> such that <em>a</em> + <em>b</em> + <em>c</em> = 0? Find all unique triplets in the array which gives the sum of zero.</p>

<p><strong>Note:</strong></p>

<p>The solution set must not contain duplicate triplets.</p>

<p><strong>Example:</strong></p>

<pre>Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum Closest (Medium)](https://leetcode.com/problems/3sum-closest/)
* [4Sum (Medium)](https://leetcode.com/problems/4sum/)
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1.

Sort the array in ascending order.

Pin the first number as `A[i]`. For the other two numbers, we can use two pointers to scan `A[(i+1)..(N-1)]`, one from `i+1` rightward, one from `N-1` leftward.

```cpp
// Problem: https://leetcode.com/problems/3sum/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int s=i+1, e=n-1;
                while(s<e){
                    int sum = nums[i] + nums[s] + nums[e];
                    if(sum == 0){
                        ans.push_back({nums[i],nums[s],nums[e]});
                        while(s<e && nums[s]==nums[s+1]) 
                            s++;
                        while(s<e && nums[e]==nums[e-1])
                            e--;
                        s++;
                        e--;
                    }
                    else if(sum < 0)
                        s++;
                    else 
                        e--;
                }
            }
        }
        return ans;
    }
};
```
