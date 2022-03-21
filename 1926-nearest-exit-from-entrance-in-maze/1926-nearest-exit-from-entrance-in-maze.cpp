class Solution {
public:

    vector<vector<int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = INT_MAX;
        queue<vector<int>> q;
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        maze[entrance[0]][entrance[1]] = '+';
        for(int i=0;i<maze.size();i++) {
            if(maze[i][0] == '.') {
                q.push({i,0});
                distance[i][0] = 0;
            }
            if(maze[i][maze[0].size()-1] == '.') {
                q.push({i,(int)maze[0].size()-1});
                distance[i][maze[0].size()-1] = 0; 
            }
        }
        
        for(int i=1;i<maze[0].size()-1;i++) {
            if(maze[0][i] == '.') {
                q.push({0,i});
                distance[0][i] = 0;
            }
            
            if(maze[maze.size()-1][i] == '.') {
                q.push({(int)maze.size()-1,i});
                distance[(int)maze.size()-1][i] = 0;
            }
        }
        maze[entrance[0]][entrance[1]] = '.';
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();

            if(i == entrance[0] && j == entrance[1]) {
                continue;
            }
    
            for(int k=0;k<directions.size();k++) {
                int newI = i + directions[k][0];
                int newJ = j + directions[k][1];
                
                if(newI >= 0 && newI < maze.size() && newJ >= 0 && newJ < maze[0].size() 
                  && maze[newI][newJ] == '.' && distance[newI][newJ] > 1 + distance[i][j]) {
                    distance[newI][newJ] = 1 + distance[i][j];
                    q.push({newI, newJ});
                }
            }
        }
        if(distance[entrance[0]][entrance[1]] == INT_MAX) distance[entrance[0]][entrance[1]] = -1;
        return distance[entrance[0]][entrance[1]];
    }
};