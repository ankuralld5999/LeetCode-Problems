// Problem: https://leetcode.com/problems/single-number-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x:nums)
            m[x]++;
        for(auto x:m)
            if(x.second==1)
                return x.first;
        return -1;
    }
};
