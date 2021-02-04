// Problem: https://leetcode.com/problems/insert-interval/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0], e = newInterval[1], pos = 0;
        vector<vector<int>> ans;
        for (auto &intv : intervals) {
            if (intv[1] < s) {
                ans.push_back(intv);
                ++pos;
            } else if (intv[0] > e) ans.push_back(intv);
            else {
                s = min(s, intv[0]);
                e = max(e, intv[1]);
            }
        }
        ans.insert(begin(ans) + pos, { s, e });
        return ans;
    }
};
