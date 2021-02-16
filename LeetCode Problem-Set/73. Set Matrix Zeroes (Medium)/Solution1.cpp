// Problem : https://leetcode.com/problems/set-matrix-zeroes/
// Author : https://github.com/ankuralld5999
// Time: O(M*N)
// Space: O(N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& M) {
        int n = M.size();
        int m = M[0].size();
        vector<int> row, col;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(int i=0; i<row.size(); i++)
            for(int j=0; j<m; j++)
                M[row[i]][j] = 0;
        
        for(int i=0; i<col.size(); i++)
            for(int j=0; j<n; j++)
                M[j][col[i]] = 0;
        
    }
};
