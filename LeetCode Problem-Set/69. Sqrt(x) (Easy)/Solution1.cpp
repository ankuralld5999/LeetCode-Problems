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
