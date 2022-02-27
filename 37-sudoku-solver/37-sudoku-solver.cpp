class Solution {
public:
    unordered_map<int,unordered_map<int,bool>> rows; 
    unordered_map<int,unordered_map<int,bool>> cols; 
    unordered_map<int,unordered_map<int,bool>> boxes; 
    
    int findBox(int i, int j) {
        return (i/3)*3 + j/3;
    }
    
    bool canPlace(int i,int j, int k) {
        return !rows[i][k] && !cols[j][k] && !boxes[findBox(i,j)][k]; 
    }
    void placeNum(int i, int j, int k, vector<vector<char>> &board) {
        rows[i][k] = true;
        cols[j][k] = true;
        boxes[findBox(i,j)][k] = true;
        board[i][j] = '0' + k;
    }
    
    void removeNum(int i, int j, int k, vector<vector<char>> &board) {
        rows[i][k] = false;
        cols[j][k] = false;
        boxes[findBox(i,j)][k] = false;
        board[i][j] = '.';
    }
    
    bool solve(int i, int j, vector<vector<char>> &board) {
        if(i == 9) return true;
        if(j == 9) return solve(i+1, 0, board);
        if(board[i][j] != '.') return solve(i,j+1, board);
        
        for(int k=1;k<=9;k++) {
            if(canPlace(i,j,k)) {
                placeNum(i,j,k,board);
                if(solve(i,j+1,board)) return true;
                removeNum(i,j,k,board);
            }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
       rows = {};
       cols = {};
       boxes = {};
       for(int i=0;i<board.size();i++) {
           for(int j=0;j<board[0].size();j++) {
               if(board[i][j] != '.') {
                   int num = board[i][j] - '0';
                   rows[i][num] = true;
                   cols[j][num] = true;
                   boxes[findBox(i,j)][num] = true;
               }
           }
       }
       solve(0,0,board);
    }
};