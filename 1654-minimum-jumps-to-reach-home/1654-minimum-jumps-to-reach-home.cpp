class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        int maxVal = 10000;
        unordered_map<int,unordered_map<int,bool>> visited;

        for(int i=0;i<forbidden.size();i++) {
            visited[forbidden[i]][0] = true;
            visited[forbidden[i]][1] = true;
        }
        
        queue<vector<int>> q;
        q.push({0,0,0});
        visited[0][0] = true;

        while(!q.empty()) {
            int pos = q.front()[0];
            int cost = q.front()[1];
            int backward = q.front()[2];
            q.pop();
            
            if(pos == x) return cost;
            int front = pos+a;
            int back = pos-b;
            
            if(front <= maxVal && (visited.find(front) == visited.end() || visited[front].find(0) == visited[front].end())) {
                visited[pos+a][0] = true;
                q.push({pos+a,cost+1,0});
            }
            
            if(backward == 0 && back >= 0 && (visited.find(back) == visited.end() || visited[back].find(1) == visited[back].end())) {
                visited[back][1] = true;
                q.push({pos-b, cost+1, 1});
            }
        }
        
        return -1;
    }
};