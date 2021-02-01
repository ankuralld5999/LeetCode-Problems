// Problem: https://leetcode.com/problems/n-queens/
// Author: github.com/ankuralld5999
class Solution {
private:
        char chessBoard[16][16];
        int NLine;
        int w, h;
        vector<vector<string> > ans;
public:
    void DFS(int nowLine) {
            if (nowLine == NLine) {  
                writeIn();
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
        void writeIn() {
            vector<string> ansPart;
            for (int i = 0; i < h; i++) {
                string temp;
                for (int j = 0; j < w; j++) {
                    temp.push_back(chessBoard[i][j]);
                }
                ansPart.push_back(temp);
            }
            ans.push_back(ansPart);
        }
    vector<vector<string>> solveNQueens(int n) {
        NLine = n;
            w = n;
            h = n;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    chessBoard[i][j] = '.';
                }
            }
            ans.clear();  
            DFS(0);
            return ans;
    }
};
