// Problem: https://leetcode.com/problems/merge-intervals/
// Author: https://github.com/ankuralld5999
class Solution {
public:
    vector<int> makeInterval(int intervalStart, int intervalEnd) {
        vector<int> interval(2);
        interval[0] = intervalStart;
        interval[1] = intervalEnd;
        return interval;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end());
        int intervalStart = intervals[0][0], intervalEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= intervalStart && intervals[i][0] <= intervalEnd) {
                intervalEnd = max(intervalEnd, intervals[i][1]);
            }
            else{
                ans.push_back(makeInterval(intervalStart, intervalEnd));
                intervalStart = intervals[i][0];
                intervalEnd = intervals[i][1];
            }
        }
        ans.push_back(makeInterval(intervalStart, intervalEnd));
        return ans;
    }
};
