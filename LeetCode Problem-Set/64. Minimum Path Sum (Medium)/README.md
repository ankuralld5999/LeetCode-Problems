# [64. Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)

<p>Given a <em>m</em> x <em>n</em> grid filled with non-negative numbers, find a path from top left to bottom right which <em>minimizes</em> the sum of all numbers along its path.</p>

<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>
[
&nbsp; [1,3,1],
  [1,5,1],
  [4,2,1]
]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1â†’3â†’1â†’1â†’1 minimizes the sum.
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)

## Solution 1. DP

```cpp
// Problem: https://leetcode.com/problems/minimum-path-sum/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1)
                    continue;
                if(i==m-1)
                    grid[i][j] += grid[i][j+1];
                else if(j==n-1)
                    grid[i][j] += grid[i+1][j];
                else
                    grid[i][j] += min(grid[i][j+1], grid[i+1][j]);
            }
        for(auto i : grid){
            for(auto x : i)
                cout << x << " ";
            cout << "\n";
        }
        return grid[0][0];
    }
};
```
