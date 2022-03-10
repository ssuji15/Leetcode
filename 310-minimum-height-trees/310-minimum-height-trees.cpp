class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n < 2) {
            vector<int> result;
            for(int i=0;i<n;i++) {
                result.push_back(i);
            }
            return result;
        }
        unordered_map<int, vector<int>> adjacentNodes;
        unordered_map<int, int> incomingNodes;
        vector<int> visited(n, false);
        for(int i=0;i<edges.size();i++) {
            adjacentNodes[edges[i][0]].push_back(edges[i][1]);
            adjacentNodes[edges[i][1]].push_back(edges[i][0]);
            incomingNodes[edges[i][0]]++;
            incomingNodes[edges[i][1]]++;
        }
        vector<int> q;
        for(int i=0;i<n;i++) {
            if(incomingNodes[i] == 1) {
                q.push_back(i);
                visited[i] = true;
            }
        }
        int remainingNodes = n;
        while(remainingNodes > 2) {
            remainingNodes -= q.size();
            vector<int> temp;
            for(int i=0;i<q.size();i++) {
                cout<<q[i]<<" ";
                for(int j=0;j<adjacentNodes[q[i]].size();j++) {
                    incomingNodes[adjacentNodes[q[i]][j]]--;
                    if(incomingNodes[adjacentNodes[q[i]][j]] == 1) {
                        visited[adjacentNodes[q[i]][j]] = true;
                        temp.push_back(adjacentNodes[q[i]][j]);
                    }
                }
            }
            cout<<endl;
            q = temp;
        }
        return q;
    }
};