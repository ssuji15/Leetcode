class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    bool find(int i, int j, vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int idx) {

        if(board[i][j] != word[idx]) return false;
        if(idx+1 == word.length()) return true;

        visited[i][j] = true;
        
        for(int k=0;k<directions.size();k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            
            if(newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size()
              && !visited[newI][newJ]) {
                if(find(newI, newJ, board, word, visited, idx+1)) return true;
            }
        }
        
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
                if(find(i,j,board,word,visited, 0)) return true;
            }
        }
        
        return false;
    }
};