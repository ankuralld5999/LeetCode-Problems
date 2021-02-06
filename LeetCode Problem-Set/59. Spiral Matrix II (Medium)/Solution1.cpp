// Problem: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        int n = N;
        if(n == 1)
            return {{1}};
        vector<vector<int>> v;
        int arr[n][n];
        int i=0, j=0, dir=0, num=1, square=n*n;
        while(num <= square){
            switch(dir){
                case 0:
                    for(int k=0; k<n; k++)
                        arr[i][j++] = num++;
                    i++;
                    j--;
                    n--;
                    dir = (dir+1)%4;
                    break;
                case 1:
                    for(int k=0; k<n; k++)
                        arr[i++][j] = num++;
                    i--;
                    j--;
                    dir = (dir+1)%4;
                    break;
                case 2:
                    for(int k=0; k<n; k++)
                        arr[i][j--] = num++;
                    i--;
                    j++;
                    n--;
                    dir = (dir+1)%4;
                    break;
                case 3:
                    for(int k=0; k<n; k++)
                        arr[i--][j] = num++;
                    i++;
                    j++;
                    dir = (dir+1)%4;
                    break;
                default:
                    break;
            }
        }
        for(i=0; i<N; i++){
            vector<int> r;
            for(j=0; j<N; j++)
                r.push_back(arr[i][j]);
            v.push_back(r);
            for(j=0; j<N; j++)
                r.pop_back();
        }
        return v;
    }
};
