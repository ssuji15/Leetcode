class Solution {
public:
    void dfs(string &s, int idx, vector<bool> &visited, vector<int> &indices, string &temp,
             unordered_map<int,vector<int>> &adjacent) {
        
        visited[idx] = true;
        indices.push_back(idx);
        temp += s[idx];
        
        for(int i=0;i<adjacent[idx].size();i++) {
            if(!visited[adjacent[idx][i]]) {
                dfs(s,adjacent[idx][i], visited, indices, temp, adjacent);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string result(s);
        
        unordered_map<int,vector<int>> adjacent;
        vector<int> indices;
        string curChars = "";
        vector<bool> visited(s.length(), false);
        
        for(int i=0;i<pairs.size();i++) {
            adjacent[pairs[i][0]].push_back(pairs[i][1]);
            adjacent[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0;i<s.length();i++) {
            if(!visited[i]) {
                indices = {};
                curChars = "";
                
                dfs(s,i,visited,indices,curChars,adjacent);
                sort(indices.begin(),indices.end());
                sort(curChars.begin(),curChars.end());
                
                for(int j=0;j<indices.size();j++) {
                    result[indices[j]] = curChars[j];
                }
            }
        }
        
        return result;
    }
};