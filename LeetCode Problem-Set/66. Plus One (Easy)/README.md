# [66. Plus One (Easy)](https://leetcode.com/problems/plus-one/)

<p>Given a <strong>non-empty</strong> array of digits&nbsp;representing a non-negative integer, plus one to the integer.</p>

<p>The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.</p>

<p>You may assume the integer does not contain any leading zero, except the number 0 itself.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,2,3]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong> The array represents the integer 123.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [4,3,2,1]
<strong>Output:</strong> [4,3,2,2]
<strong>Explanation:</strong> The array represents the integer 4321.
</pre>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)
* [Add Binary (Easy)](https://leetcode.com/problems/add-binary/)
* [Plus One Linked List (Medium)](https://leetcode.com/problems/plus-one-linked-list/)
* [Add to Array-Form of Integer (Easy)](https://leetcode.com/problems/add-to-array-form-of-integer/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/plus-one/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i=digits.size()-1;
        while(carry && i>=0){
            if(digits[i]==9){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i]++;
                carry = 0;
            }
            i--;
        }
        if(carry == 1){
            vector<int> v = {1};
            for(int x : digits)
                v.push_back(x);
            return v;
        }
        return digits;
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/plus-one/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int i = A.size() - 1, carry = 1;
        for (; i >= 0 && carry; --i) {
            carry += A[i];
            A[i] = carry % 10;
            carry /= 10;
        }
        if (carry) A.insert(begin(A), carry);
        return A;
    }
};
```
