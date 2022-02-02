class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    void solve(vector<vector<char>>& board) {
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        queue<vector<int>> q;
        
        for(int i=0;i<board[0].size();i++) {
            if(board[0][i] == 'O') {
                q.push({0,i});
            }
        }
        
        for(int i=1;i<board.size();i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
            }
        }
        
        for(int i=1;i<board[0].size();i++) {
            if(board[board.size()-1][i] == 'O') {
                q.push({(int)board.size()-1, i});
            }
        }
        
        for(int i=1;i<board.size()-1;i++) {
            if(board[i][board[0].size()-1] == 'O') {
                q.push({i, (int)board[0].size()-1});
            }
        }
        
        while(!q.empty()) {
            
            vector<int> temp = q.front();
            q.pop();
            
            int i = temp[0];
            int j = temp[1];
            
            visited[i][j] = true;
            
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size()
                  && board[newI][newJ] == 'O' && !visited[newI][newJ]) {
                    q.push({newI, newJ});
                }
            }
        }
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                } 
            }
        }
    }
};