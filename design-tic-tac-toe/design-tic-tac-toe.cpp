class TicTacToe {
public:
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<int> leftDiagonal = vector<int>(2,0);
    vector<int> rightDiagonal = vector<int>(2,0);
    int size;
    TicTacToe(int n) {
        row = vector<vector<int>>(n,vector<int>(2,0));
        col = vector<vector<int>>(n,vector<int>(2,0));
        size = n;
    }
    
    int move(int row, int col, int player) {
        this->row[row][player-1]++;
        this->col[col][player-1]++;
        
        if(row == col) {
            leftDiagonal[player-1]++;
        };
        
        if(col == this->size-row-1) {
            rightDiagonal[player-1]++;
        }
        
        if(this->row[row][player-1] == size || this->col[col][player-1] == size || leftDiagonal[player-1] == size
          || rightDiagonal[player-1] == size) return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */