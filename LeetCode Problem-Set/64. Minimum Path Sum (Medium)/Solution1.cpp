/ Problem: https://leetcode.com/problems/minimum-path-sum/
// Author: github.com/ankuralld5999
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1)
                    continue;
                if(i==m-1)
                    grid[i][j] += grid[i][j+1];
                else if(j==n-1)
                    grid[i][j] += grid[i+1][j];
                else
                    grid[i][j] += min(grid[i][j+1], grid[i+1][j]);
            }
        for(auto i : grid){
            for(auto x : i)
                cout << x << " ";
            cout << "\n";
        }
        return grid[0][0];
    }
};
