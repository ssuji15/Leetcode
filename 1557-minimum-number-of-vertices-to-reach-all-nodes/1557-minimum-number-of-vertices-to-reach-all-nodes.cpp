class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incomingEdges(n, 0);
        for(int i=0;i<edges.size();i++) {
            incomingEdges[edges[i][1]]++;
        }
        
        vector<int> result;
        for(int i=0;i<n;i++) {
            if(incomingEdges[i] == 0) result.push_back(i);
        }
        
        return result;
    }
};