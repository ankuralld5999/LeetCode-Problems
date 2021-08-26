// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) 
		ans += max(prices[i] - prices[i - 1], 0);
        return ans;
    }
};
