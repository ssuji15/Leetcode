class Solution {
public:
    vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};

    int dfs(int i, int j, int moves, int m, int n, vector<vector<vector<int>>> &visited) {
        if(i<0 || j<0 || i==m || j==n) return 1;
        if(moves == 0) return 0;
        if(visited[i][j][moves] != -1) return visited[i][j][moves];
        visited[i][j][moves] = 0;
        for(int k=0;k<dir.size();k++) {
            int newI = dir[k][0] + i;
            int newJ = dir[k][1] + j;
            visited[i][j][moves] = ((dfs(newI, newJ, moves-1, m, n, visited) % 1000000007) + visited[i][j][moves]) % 1000000007;
        }
        return visited[i][j][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n,vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, maxMove, m, n, visited);
    }
};