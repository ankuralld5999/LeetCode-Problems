// Problem: https://leetcode.com/problems/subsets/
// Author: github.com/ankuralld5999
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return {{}};
        vector<vector<int>> result1;
        vector<vector<int>> result2 = {{}};
        for(int x : nums){
            int n = result2.size();
            for(int i=0; i<n; i++){
                vector<int> r = result2[i];
                r.push_back(x);
                result2.push_back(r);
            }
        }
        return result2;
    }
};
