class Solution {
public:
    
    vector<int> parent;
    
    int find(int node) {
        if(parent[node] >= 0) {
            int x = find(parent[node]);
            parent[node] = x;
            return x;
        }
        return node;
    }
    
    void doUnion(int node1, int node2) {
        int parentNode1 = find(node1);
        int parentNode2 = find(node2);
        
        if(parentNode1 == parentNode2) return;
        
        if(parent[parentNode1] <= parent[parentNode2]) {
            parent[parentNode1] += parent[parentNode2];
            parent[parentNode2] = parentNode1;
        }
        else {
            parent[parentNode2] += parent[parentNode1];
            parent[parentNode1] = parentNode2;
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent = vector<int>(1001, -1);
        
        for(int i=0;i<edges.size();i++) {
            if(find(edges[i][0]) == find(edges[i][1])) return edges[i];
            doUnion(edges[i][0], edges[i][1]);
        }
        return {};
    }
};