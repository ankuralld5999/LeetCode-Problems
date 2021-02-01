// Problem: https://leetcode.com/problems/n-queens-ii/submissions/
// Author: https://github.com/ankuralld5999
class Solution {
private:
        char chessBoard[16][16];
        int NLine;
        int w, h;
        int ans;
public:
    void DFS(int nowLine) {
            if (nowLine == NLine) {  
                ans++;
                return;
            }
            for (int j = 0; j < NLine; j++) {
                if (isValid(nowLine, j)) {
                    chessBoard[nowLine][j] = 'Q';
                    DFS(nowLine + 1);
                    chessBoard[nowLine][j] = '.';
                }
            }
        }
        bool isValid(int i, int j) {  
            for (int k = 0; k < w; k++) {
                if (chessBoard[i][k] == 'Q') return false; 
                if (chessBoard[k][j] == 'Q') return false;  
            }
            for (int k = 0; k < h; k++) {
                if (inBoard(i + 1 * k, j + 1 * k) && chessBoard[i + 1 * k][j + 1 * k] == 'Q') return false;  
                if (inBoard(i - 1 * k, j - 1 * k) && chessBoard[i - 1 * k][j - 1 * k] == 'Q') return false;  
                if (inBoard(i - 1 * k, j + 1 * k) && chessBoard[i - 1 * k][j + 1 * k] == 'Q') return false;  
                if (inBoard(i + 1 * k, j - 1 * k) && chessBoard[i + 1 * k][j - 1 * k] == 'Q') return false;  
            }
            return true;
        }
        bool inBoard(int i, int j) {
            return 0 <= i && i < h && 0 <= j && j < w;
        }
        
    int totalNQueens(int n) {
        NLine = n;
        w = n;
        h = n;
        ans=0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                chessBoard[i][j] = '.';
            }
        }
        DFS(0);
        return ans;
    }
};
