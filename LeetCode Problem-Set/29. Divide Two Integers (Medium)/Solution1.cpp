// Problem: https://leetcode.com/problems/divide-two-integers/
// Author: github.com/ankuralld5999
// Time: O(logD) where D is |dividend|
// Space: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
         if (dividend==INT_MIN and divisor==-1) return INT_MAX;
        if (dividend==INT_MIN and divisor==1) return INT_MIN;
        
        bool sign = (dividend < 0) ^ (divisor < 0);
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        
        int ans = 0;
        
        int i=1, accum=divisor;
        while (accum>=INT_MIN>>1 && dividend<=accum+accum) {
            i <<= 1;
            accum += accum;
        }
        while (dividend <= divisor) {
            if (dividend <= accum){
                dividend -= accum;
                ans += i;
            }
            accum >>= 1; 
            i >>= 1;
        }
        
        return (sign ? -ans : ans);
    }
};
