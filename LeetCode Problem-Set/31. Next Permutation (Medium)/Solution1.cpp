// Problem: https://leetcode.com/problems/next-permutation
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void reverseVector(int i,int j,vector<int>& nums){
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-2;
        while(k>=0 && nums[k]>=nums[k+1]) k--;
        if(k==-1){
            reverseVector(0,nums.size()-1,nums);
            return;
        }
        for(int i=nums.size()-1;i>k;i--)
            if(nums[i]>nums[k]){
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=temp;
                break;
            }
        reverseVector(k+1,nums.size()-1,nums);
        return;
    } 
};
