# [136. Single Number (Easy)](https://leetcode.com/problems/single-number/)

<p>Given a <strong>non-empty</strong>&nbsp;array of integers, every element appears <em>twice</em> except for one. Find that single one.</p>

<p><strong>Note:</strong></p>

<p>Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,2,1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [4,1,2,1,2]
<strong>Output:</strong> 4
</pre>


## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/single-number/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x:nums)
            m[x]++;
        for(auto it:m)
            if(it.second == 1)
                return it.first;
        return -1;
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/single-number/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) ans ^= n;
        return ans;
    }
};
```
