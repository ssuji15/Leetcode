class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0, rows = maze.size(), cols = maze[0].size();
        while(!q.empty()) {
            steps++;
            int size = q.size();
            while(size--) {
                pair<int,int> pos = q.front();
                q.pop();
                for(int k=0;k<4;k++) {
                    int newI = pos.first + directions[k][0];
                    int newJ = pos.second + directions[k][1];
                    if(newI >= 0 && newI < rows && newJ >= 0 && newJ < cols
                       && maze[newI][newJ] == '.') {
                        if(newI == 0 || newI == rows-1 || newJ == 0
                           || newJ == cols-1) {
                            return steps;
                        }
                        maze[newI][newJ] = '+';
                        q.push({newI, newJ});
                    }
                }
            }
        }
        return -1;
    }
};