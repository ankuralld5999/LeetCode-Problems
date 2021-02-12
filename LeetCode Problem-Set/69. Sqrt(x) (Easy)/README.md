# [69. Sqrt(x) (Easy)](https://leetcode.com/problems/sqrtx/)

<p>Given a non-negative integer x, compute and return the square root of x.</p>

<p>Since the return type is an integer, the decimal digits are <strong>truncated</strong>, and only <strong>the integer part</strong> of the result is returned.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> x = 4
<strong>Output:</strong> 2</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 8
<strong>Output:</strong> 2</pre>
<strong>Explanation:</strong> The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.</pre>



## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/sqrtx/
// Author: github.com/ankuralld5999
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        long long int n = 1;
        while(n*n <= x){
            n++;
        }
        return n-1;
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/sqrtx/
// Author: github.com/ankuralld5999
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        int L = 1, R = INT_MAX;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (x / M == M) return M;
            else if (x / M > M) L = M + 1;
            else R = M - 1;
        }
        return x / L >= L ? L : L - 1;
    }
};
```

## Solution 3.

```cpp
// Problem: https://leetcode.com/problems/sqrtx/
// Author: github.com/ankuralld5999
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// Newton's method
class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};
```

