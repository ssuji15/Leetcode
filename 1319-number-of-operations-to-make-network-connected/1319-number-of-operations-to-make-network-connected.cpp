class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        int par = parent[x];
        if(par >= 0) {
            int newPar = find(par);
            parent[x] = newPar;
            return newPar;
        }
        return x;
    }
    
    void weightedUnion(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y) return;
        if(parent[parent_x] <= parent[parent_y]) {
            parent[parent_x] += parent[parent_y];
            parent[parent_y] = parent_x;
        }
        else {
            parent[parent_y] += parent[parent_x];
            parent[parent_x] = parent_y;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent = vector<int>(n,-1);
        int extraEdges = 0, treeEdges = 0;
        for(int i=0;i<connections.size();i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            if(find(x) == find(y)) {
                extraEdges++;
            }
            else {
                weightedUnion(x,y);
                treeEdges++;
            }
            
        }

        int noOfNodesNotConnected = n - (treeEdges+1);

        if(extraEdges >= noOfNodesNotConnected) {
            return noOfNodesNotConnected;
        }
        return -1;
    }
};