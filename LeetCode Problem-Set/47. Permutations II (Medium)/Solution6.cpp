// Problem: https://leetcode.com/problems/permutations-ii
// Author: github.com/ankuralld5999
// Time: O(N!)
// Space: O(N)
class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& permutation,
                   vector<bool>& posibility, vector<vector<int>>& result){
        if(permutation.size() == nums.size())
            result.push_back(permutation);
        else{
            for(int i=0; i<posibility.size(); i++){
                if(i>0 && posibility[i-1] && nums[i]==nums[i-1])
                    continue;
                if(posibility[i]){
                    permutation.push_back(nums[i]);
                    posibility[i] = false;
                    backtrack(nums, permutation, posibility, result);
                    posibility[i] = true;
                    permutation.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<bool> posibility(nums.size(), true);
        vector<int> permutation;
        
        backtrack(nums, permutation, posibility, result);
        return result;
    }
};
