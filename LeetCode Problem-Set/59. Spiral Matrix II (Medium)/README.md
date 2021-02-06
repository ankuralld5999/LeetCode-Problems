# [59. Spiral Matrix II (Medium)](https://leetcode.com/problems/spiral-matrix-ii/)

<p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Spiral Matrix (Medium)](https://leetcode.com/problems/spiral-matrix/)
* [Spiral Matrix III (Medium)](https://leetcode.com/problems/spiral-matrix-iii/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        int n = N;
        if(n == 1)
            return {{1}};
        vector<vector<int>> v;
        int arr[n][n];
        int i=0, j=0, dir=0, num=1, square=n*n;
        while(num <= square){
            switch(dir){
                case 0:
                    for(int k=0; k<n; k++)
                        arr[i][j++] = num++;
                    i++;
                    j--;
                    n--;
                    dir = (dir+1)%4;
                    break;
                case 1:
                    for(int k=0; k<n; k++)
                        arr[i++][j] = num++;
                    i--;
                    j--;
                    dir = (dir+1)%4;
                    break;
                case 2:
                    for(int k=0; k<n; k++)
                        arr[i][j--] = num++;
                    i--;
                    j++;
                    n--;
                    dir = (dir+1)%4;
                    break;
                case 3:
                    for(int k=0; k<n; k++)
                        arr[i--][j] = num++;
                    i++;
                    j++;
                    dir = (dir+1)%4;
                    break;
                default:
                    break;
            }
        }
        for(i=0; i<N; i++){
            vector<int> r;
            for(j=0; j<N; j++)
                r.push_back(arr[i][j]);
            v.push_back(r);
            for(j=0; j<N; j++)
                r.pop_back();
        }
        return v;
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0, d = 1; i < n / 2; ++i) {
            int len = n - 2 * i - 1;
            for (int j = 0; j < len; ++j) ans[i][i + j] = d++;
            for (int j = 0; j < len; ++j) ans[i + j][n - i - 1] = d++;
            for (int j = 0; j < len; ++j) ans[n - i - 1][n - i - j - 1] = d++;
            for (int j = 0; j < len; ++j) ans[n - i - j - 1][i] = d++;
        }
        if (n % 2) ans[n / 2][n / 2] = n * n;
        return ans;
    }
};
```
