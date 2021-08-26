// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int buy = INT_MIN, sell = 0;
        for (int n : A) {
            buy = max(buy, -n);
            sell = max(sell, buy + n);
        }
        return sell;
    }
};
