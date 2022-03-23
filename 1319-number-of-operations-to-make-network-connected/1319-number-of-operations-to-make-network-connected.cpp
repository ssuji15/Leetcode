class Solution {
public:
    vector<int> parents;
    void weightedUnion(int idx1, int idx2) {
        int parent1 = find(idx1);
        int parent2 = find(idx2);
        if(parent1 == parent2) return;
        if(parents[parent1] <= parents[parent2]) {
            parents[parent1] += parents[parent2];
            parents[parent2] = parent1;
        }
        else {
            parents[parent2] += parents[parent1];
            parents[parent1] = parent2;
        }
    }
    
    int find(int idx) {
        if(parents[idx] >= 0) {
            int parent = find(parents[idx]);
            parents[idx] = parent;
            return parent;
        }
        return idx;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0, unconnected=0;
        parents = vector<int>(n,-1);
        for(int i=0;i<connections.size();i++) {
            if(find(connections[i][0]) == find(connections[i][1])) {
                count++;
            }
            weightedUnion(connections[i][0], connections[i][1]);
        }
        
        for(int i=0;i<n;i++) {
            if(parents[i] < 0) {
                unconnected++;
            }
        }
        
        if(unconnected-1 > count) return -1;
        return unconnected-1;
    }
};