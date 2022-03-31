class Solution {
public:
    vector<vector<int>> directions={{0,-1}, {-1,0}, {0,1}, {1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dependent(m, vector<int>(n,0));
        queue<vector<int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int val;
                
                for(int k=0;k<directions.size();k++) {
                    int newI = i + directions[k][0];
                    int newJ = j + directions[k][1];
                    if(newI >= 0 && newJ >= 0 && newI < m && newJ < n
                       && matrix[newI][newJ] > matrix[i][j]) {
                        dependent[i][j]++;
                    }
                }

                if(dependent[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                for(int k=0;k<directions.size();k++) {
                    int newI = i + directions[k][0];
                    int newJ = j + directions[k][1];
                    if(newI >= 0 && newJ >= 0 && newI < m && newJ < n 
                       && dependent[newI][newJ] > 0 && matrix[i][j] > matrix[newI][newJ]) {
                        dependent[newI][newJ]--;
                        if(dependent[newI][newJ] == 0) {
                            q.push({newI, newJ});
                        }
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};