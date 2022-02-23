class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>> &childrens, vector<int> &result) {
        result.push_back(node);
        for(int i=0;i<childrens[node].size();i++) {
            dfs(childrens[node][i], childrens, result);
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        unordered_map<int,vector<int>> childrens;
        for(int i=0;i<pid.size();i++) {
            if(ppid[i] != 0) {
                childrens[ppid[i]].push_back(pid[i]);
            }
        }
        
        dfs(kill, childrens, result);
        return result;
    }
};