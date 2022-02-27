class Solution {
public:
    bool placeQueen(int i, int j, vector<string> &board, int n) {
        for(int k=0;k<n;k++) {
            if(board[i][k] == 'Q') return false;
        }
        
        for(int k=0;k<n;k++) {
            if(board[k][j] == 'Q') return false;
        }
        int tempI = i, tempJ = j;
        while(tempI >= 0 && tempJ >= 0) {
            if(board[tempI][tempJ] == 'Q') return false;
            tempI--;
            tempJ--;
        }
        tempI = i;
        tempJ = j;
        while(tempI < n && tempJ < n) {
            if(board[tempI][tempJ] == 'Q') return false;
            tempI++;
            tempJ++;
        }
        
        tempI = i;
        tempJ = j;
        while(tempI >= 0 && tempJ < n) {
            if(board[tempI][tempJ] == 'Q') return false;
            tempI--;
            tempJ++;
        }
        
        tempI = i;
        tempJ = j;
        while(tempI < n && tempJ >= 0) {
            if(board[tempI][tempJ] == 'Q') return false;
            tempI++;
            tempJ--;
        }
        
        return true;
    }
    void solve(int i, vector<string> &board, int n, vector<vector<string>> &result) {
        if(i == n) {
            result.push_back(board);
            return;
        }
        for(int j=0;j<n;j++) {
            if(placeQueen(i,j,board,n)) {
                board[i][j] = 'Q';
                solve(i+1, board, n, result);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        for(int i=0;i<n;i++) {
            board.push_back(string(n,'.'));
        }
        solve(0,board,n,result);
        return result;
    }
};