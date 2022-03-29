class Solution {
public:
    bool dfs(int node, vector<int> &color, unordered_map<int,vector<int>> &adjacent) {
        for(int i=0;i<adjacent[node].size();i++) {
            int newNode = adjacent[node][i];
            if(color[newNode] == color[node]) return false;
            if(color[newNode] == 0) {
                color[newNode] = -color[node];
                if(!dfs(newNode,color,adjacent)) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjacent;
        for(int i=0;i<dislikes.size();i++) {
            adjacent[dislikes[i][0]].push_back(dislikes[i][1]);
            adjacent[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(n+1, 0);
        for(int i=1;i<=n;i++) {
            if(color[i] == 0) {
                color[i] = 1;
                if(!dfs(i, color, adjacent)) return false;
            }
        }
        return true;
    }
};



