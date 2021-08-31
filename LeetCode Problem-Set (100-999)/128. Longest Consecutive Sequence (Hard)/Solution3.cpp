// Problem: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        
        for(int num : nums)
            hashset.insert(num);
        
        int longest_streak = 0;
        
        for(int num : nums){
            if(!hashset.count(num-1)){
                int current_streak = 1;
                int current_num = num;
                
                while(hashset.count(current_num+1)){
                    current_streak += 1;
                    current_num += 1;
                }
                
                longest_streak = max(longest_streak, current_streak);
            }
        }
        return longest_streak;
    }
};
