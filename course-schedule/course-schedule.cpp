class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> incoming;
        unordered_map<int, vector<int>> adjacent;
        
        for(int i=0;i<numCourses;i++) {
            incoming[i] = 0;
        }
        
        for(int i=0;i<prerequisites.size();i++) {
            incoming[prerequisites[i][0]]++;
            adjacent[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(incoming[i] == 0) {
                q.push(i);
            }
        }
        int studied = 0;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            studied++;
            for(int i=0;i<adjacent[course].size();i++) {
                int curCourse = adjacent[course][i];
                incoming[curCourse]--;
                if(incoming[curCourse] == 0) {
                    q.push(curCourse);
                }
            }
        }
        
        return q.empty() && studied == numCourses;
    }
};