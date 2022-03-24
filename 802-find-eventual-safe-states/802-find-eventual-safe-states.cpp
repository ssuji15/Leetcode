class Solution {
public:
    set<int> terminalNodes;

    void dfs(int node, vector<int> &state, vector<vector<int>> &graph) {
        
        bool curState = 1;
        state[node] = 2;
        for(int i=0;i<graph[node].size();i++) {
            int newNode = graph[node][i];
            if(state[newNode] == -1) {
                dfs(newNode, state, graph);
                if(state[newNode] == 0) curState = 0;
            }
            else if(state[newNode] == 0 || state[newNode] == 2) {
                curState = 0;
            }
        }
        if(curState==1) {
            terminalNodes.insert(node);
        }
        state[node] = curState;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> state(graph.size(), -1);
        for(int i=0;i<graph.size();i++) {
            if(state[i] == -1) {
                dfs(i, state, graph);
            }
        }
        vector<int> result(terminalNodes.begin(), terminalNodes.end());
        return result;
    }
};