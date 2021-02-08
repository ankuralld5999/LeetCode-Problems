# [63. Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)

<p>A robot is located at the top-left corner of a <em>m</em> x <em>n</em> grid (marked 'Start' in the diagram below).</p>

<p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>

<p>Now consider if some obstacles are added to the grids. How many unique paths would there be?</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;"></p>

<p>An obstacle and empty space is marked as <code>1</code> and <code>0</code> respectively in the grid.</p>

<p><strong>Note:</strong> <em>m</em> and <em>n</em> will be at most 100.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:
</strong>[
&nbsp; [0,0,0],
&nbsp; [0,1,0],
&nbsp; [0,0,0]
]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right -&gt; Right
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Mathworks](https://leetcode.com/company/mathworks), [Bloomberg](https://leetcode.com/company/bloomberg), [GoDaddy](https://leetcode.com/company/godaddy), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Lyft](https://leetcode.com/company/lyft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<int> memo(N, 0);
        memo[N - 1] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (obstacleGrid[i][j] == 1) memo[j] = 0;
                else memo[j] += j == N - 1 ? 0 : memo[j + 1];
            }
        }
        return memo[0];
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        if(v[0][0]==1)
            return 0;
        int m = v.size();
        int n = v[0].size();
        int dp[m][n];
        bool flag = false;
        for(int i=0; i<n; i++){
            if(flag || v[0][i]==1){
                flag = true;
                dp[0][i] = 0;
            }
            else
                dp[0][i] = 1;
        }
        flag = false;
        for(int i=0; i<m; i++){
            if(flag || v[i][0]==1){
                flag = true;
                dp[i][0] = 0;
            }
            else
                dp[i][0] = 1;
        }
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                if(v[i][j]==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        return dp[m-1][n-1];
    }
};
```
