// Problem: https://leetcode.com/problems/valid-sudoku/submissions/
// Author: https://github.com/ankuralld5999
class Solution {
private:
    bool checkRow(vector<vector<char>>& v){
        for(int i=0; i<9; i++){
            bool arr[9] = {false};
            for(int j=0; j<9; j++){
                if(v[i][j]=='.')
                    continue;
                else if(arr[v[i][j]-'1'])
                    return false;
                arr[v[i][j]-'1'] = true;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& v){
        for(int j=0; j<9; j++){
            bool arr[9] = {false};
            for(int i=0; i<9; i++){
                if(v[i][j]=='.')
                    continue;
                else if(arr[v[i][j]-'1'])
                    return false;
                arr[v[i][j]-'1'] = true;
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& v){
        for(int m=0; m<9; ){
            for(int n=0; n<9; ){
                bool arr[9] = {false};
                for(int i=m; i<m+3; i++){
                    for(int j=n; j<n+3; j++){
                        if(v[i][j]=='.')
                            continue;
                        else if(arr[v[i][j]-'1'])
                            return false;
                        arr[v[i][j]-'1'] = true;
                    }
                }
                n += 3;
            }
            m += 3;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        if(!checkRow(v))
            return 0;
        if(!checkCol(v))
            return 0;
        if(!checkBox(v))
            return 0;
        return 1;
    }
};
