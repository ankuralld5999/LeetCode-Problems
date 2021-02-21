// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        vector<int>::iterator it;
        for(int i=1; i<len; i++){
            if(nums[i-1] == nums[i]){
                if(count >= 1){
                    int temp = nums[i];
                    it = nums.begin()+i;
                    nums.erase(it);
                    nums.push_back(temp);
                    len--;
                    i--;
                }
                count++;
            }
            else
                count = 0;
        }
        return len;
    }
};
