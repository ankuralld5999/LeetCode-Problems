// Problem: https://leetcode.com/problems/permutations-ii
// Author: github.com/ankuralld5999
// Time: O(N!)
// Space: O(N^2)
class Solution {
private:
  vector<vector<int>> ans;
  void permute(vector<int> &nums, int start) {
    if (start == nums.size()) {
      ans.push_back(nums);
      return;
    }
    unordered_set<int> s;
    for (int i = start; i < nums.size(); ++i) {
      if (s.count(nums[i])) continue;
      swap(nums[i], nums[start]);
      permute(nums, start + 1);
      swap(nums[i], nums[start]);
      s.insert(nums[i]);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    permute(nums, 0);
    return ans;
  }
};
