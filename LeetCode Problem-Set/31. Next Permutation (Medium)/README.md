# [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)

<p>Implement <strong>next permutation</strong>, which rearranges numbers into the lexicographically next greater permutation of numbers.</p>

<p>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a></strong> and use only constant&nbsp;extra memory.</p>

<p>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.</p>

<p><code>1,2,3</code> â†’ <code>1,3,2</code><br>
<code>3,2,1</code> â†’ <code>1,2,3</code><br>
<code>1,1,5</code> â†’ <code>1,5,1</code></p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/next-permutation
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void reverseVector(int i,int j,vector<int>& nums){
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-2;
        while(k>=0 && nums[k]>=nums[k+1]) k--;
        if(k==-1){
            reverseVector(0,nums.size()-1,nums);
            return;
        }
        for(int i=nums.size()-1;i>k;i--)
            if(nums[i]>nums[k]){
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=temp;
                break;
            }
        reverseVector(k+1,nums.size()-1,nums);
        return;
    } 
};
```
