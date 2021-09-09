// Problem: https://leetcode.com/problems/single-number/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x:nums)
            m[x]++;
        for(auto it:m)
            if(it.second == 1)
                return it.first;
        return -1;
    }
};
