// Problem: https://leetcode.com/problems/sudoku-solver/
// Author: https://github.com/ankuralld5999
class Solution {
private:
    bool canfill(vector<vector<char> >& board, int &i, int &j, char &c){
	for(auto t1:board){
		if(t1[j]==c)
			return false;
	}
	for(auto t1:board[i]){
		if(t1==c)
			return false;
	}
	for(int k=i/3*3; k<3+i/3*3; k++){
		for(int l=j/3*3; l<3+j/3*3; l++){
			if(board[k][l]==c)
				return false;
		}
	}
	return true;
}

bool sodoku(vector<vector<char> >& board, int i, int j){
	if(j==9){
		j=0;
		i++;
	}
	if(i==9){
		return true;
	}
	if(board[i][j]!='.'){
		return sodoku(board, i, j+1);
	}
	for(char c='1';c<='9';c++){
		if(canfill(board, i, j, c)){
			board[i][j]=c;
			if(sodoku(board, i, j+1))
				return true;
			board[i][j]='.';
		}
	}
	return false;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        sodoku(board, 0, 0);
    }
};
