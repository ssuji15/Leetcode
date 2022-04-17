class Solution {
public:
    
    int find(vector<int> &parent, int node) {
        if(parent[node] >= 0) {
            int x = find(parent, parent[node]);
            parent[node] = x;
            return x;
        }
        return node;
    }
    
    void doUnion(vector<int> &parent, int node1, int node2) {
        int parentNode1 = find(parent, node1);
        int parentNode2 = find(parent, node2);
        
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
    
    
    vector<int> parent1, parent2;
    bool equationsPossible(vector<string>& equations) {
        parent1 = vector<int>(26, -1);
        
        for(int i=0;i<equations.size();i++) {
            if(equations[i][1] == '=') {
                doUnion(parent1, equations[i][0]-'a', equations[i][3]-'a');
            }
        }
        
        for(int i=0;i<equations.size();i++) {
            if(equations[i][1] == '!') {
                if(find(parent1, equations[i][0]-'a') == find(parent1, equations[i][3]-'a')) return false;
            }
        }
        
        return true;
    }
};