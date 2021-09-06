// Problem: https://leetcode.com/problems/gas-station
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minVal = INT_MAX, tank = 0, ans = 0, N = gas.size();
        for (int i = 0; i < N; ++i) {
            tank += gas[i] - cost[i];
            if (tank < minVal) {
                minVal = tank;
                ans = i;
            }
        }
        return tank >= 0 ? (ans + 1) % N : -1;
    }
};
