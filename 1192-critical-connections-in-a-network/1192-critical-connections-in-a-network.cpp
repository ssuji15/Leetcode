class Solution {
public:
    vector<vector<int>> result;
    vector<int> inTime;
    vector<int> minTime;
    int time;
    
    void dfs(int node, unordered_map<int,vector<int>> &adjacent, int parent) {
        inTime[node] = time;
        minTime[node] = time;
        time++;
        for(int i=0;i<adjacent[node].size();i++) {
            int newNode = adjacent[node][i];
            if(newNode == parent) continue;
            if(inTime[newNode] == -1) {
                dfs(newNode, adjacent, node);
                minTime[node] = min(minTime[node], minTime[newNode]);
                if(minTime[newNode] > inTime[node]) {
                    result.push_back({node, newNode});
                }
            }
            else {
                minTime[node] = min(minTime[node], inTime[newNode]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        result = {};
        time = 0;
        unordered_map<int,vector<int>> adjacent;
        inTime = vector<int>(n,-1);
        minTime = vector<int>(n,INT_MAX);
        
        for(int i=0;i<connections.size();i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }
        
        dfs(0,adjacent,-1);
        return result;
    }
};