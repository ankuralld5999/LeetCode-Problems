# [49. Group Anagrams (Medium)](https://leetcode.com/problems/group-anagrams/)

<p>Given an array of strings, group anagrams together.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> <code>["eat", "tea", "tan", "ate", "nat", "bat"]</code>,
<strong>Output:</strong>
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>All inputs will be in lowercase.</li>
	<li>The order of your output does not&nbsp;matter.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Group Shifted Strings (Medium)](https://leetcode.com/problems/group-shifted-strings/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/group-anagrams/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<string,vector<string> > mymap;
        int n = strs.size();
        string temp;
        
        for(int i =0;i<n;++i)
        {
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        
        vector<vector<string> > result;
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr)
            result.push_back(itr->second);
        
        return result;
    }
};
```
