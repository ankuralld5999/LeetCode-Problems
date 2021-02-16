// Problem: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/ankuralld5999
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
            if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                bool ans;
                ans=(find(matrix[i].begin(),matrix[i].end(),target) != matrix[i].end()?true:false);
                return ans;
            }
        return false;
    }
};
