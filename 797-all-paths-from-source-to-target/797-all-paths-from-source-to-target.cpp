class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx, vector<vector<int>>& graph, vector<int> path) {
        path.push_back(idx);

        if(idx == graph.size()-1) {
            result.push_back(path);
            return;
        }
        
        for(int i=0;i<graph[idx].size();i++) {
            dfs(graph[idx][i], graph, path);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        result = {};
        dfs(0, graph, {});
        return result;
    }
};