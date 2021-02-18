# [77. Combinations (Medium)](https://leetcode.com/problems/combinations/)

<p>Given two integers <em>n</em> and <em>k</em>, return all possible combinations of <em>k</em> numbers out of 1 ... <em>n</em>.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>&nbsp;n = 4, k = 2
<strong>Output:</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)

## Solution 1. DFS

```cpp
// Problem: https://leetcode.com/problems/combinations/
// Author: github.com/ankuralld5999
// Time: O(K!)
// Space: O(K)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int n, int k, int start, vector<int> &tmp) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start, end = n - k + tmp.size(); i <= end; ++i) {
            tmp.push_back(i + 1);
            dfs(n, k, i + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(n, k, 0, tmp);
        return ans;
    }
};
```

## Solution 2. Iterative

```cpp
// Problem: https://leetcode.com/problems/combinations/
// Author: github.com/ankuralld5999
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};
```
