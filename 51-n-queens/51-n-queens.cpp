class Solution {
public:
    vector<vector<string>> result;
    bool checkDiagonals(int row, int col, vector<string> &board, int n) {
        int tempRow = row, tempCol = col;
        while(tempRow >= 0 && tempCol >= 0 && board[tempRow][tempCol] == '.') {
            tempRow--;
            tempCol--;
        }
        
        if(tempRow >= 0 && tempCol >= 0) return true;
        tempRow = row, tempCol = col;
        while(tempRow >= 0 && tempCol < n && board[tempRow][tempCol] == '.') {
            tempRow--;
            tempCol++;
        }
        
        if(tempRow >= 0 && tempCol < n) return true;
        
        return false;
    }
    void solve(int curRow, vector<bool> &cols, vector<string> &board,int n) {
        if(curRow == n) {
            result.push_back(board);
            return;
        }
        
        for(int j=0;j<n;j++) {
            if(!cols[j] && !checkDiagonals(curRow, j, board, n)) {
                board[curRow][j] = 'Q';
                cols[j] = true;
                solve(curRow+1, cols, board, n);
                board[curRow][j] = '.';
                cols[j] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false);
        vector<string> board(n, string(n,'.'));
        solve(0,cols,board,n);
        return result;
    }
};