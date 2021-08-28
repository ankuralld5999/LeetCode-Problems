# [125. Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)

<p>Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.</p>

<p><strong>Note:</strong>&nbsp;For the purpose of this problem, we define empty string as valid palindrome.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "A man, a plan, a canal: Panama"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "race a car"
<strong>Output:</strong> false
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)
* [Valid Palindrome II (Easy)](https://leetcode.com/problems/valid-palindrome-ii/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/valid-palindrome/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0, end=s.size()-1;
        
        while(start < end){
            while(start<end && !isalnum(s[start]))
                start++;
            while(start<end && !isalnum(s[end]))
                end--;
            if(start<end && (tolower(s[start++]) != tolower(s[end--])))
                return false;
        }
        return true;
    }
};
```
