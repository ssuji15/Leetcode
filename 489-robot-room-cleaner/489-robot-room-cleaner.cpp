/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    unordered_map<int,unordered_map<int,bool>> visited;
    vector<vector<int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    void goback(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void backtrack(int i, int j, Robot &robot, int direction) {
        robot.clean();
        visited[i][j] = true;
        for(int k=0;k<4;k++) {
            int curDir = (k + direction) % 4;
            
            int newI = i + directions[curDir][0];
            int newJ = j + directions[curDir][1];
            if((visited.find(newI) == visited.end()
               || visited[newI].find(newJ) == visited[newI].end())
               && robot.move()) {
                backtrack(newI, newJ, robot, curDir);
                goback(robot);
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        visited = {};
        backtrack(0,0,robot,0);
    }
};