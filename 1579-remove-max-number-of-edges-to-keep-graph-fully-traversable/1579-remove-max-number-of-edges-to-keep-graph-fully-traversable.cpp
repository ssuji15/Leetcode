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
        int parentOfNode1 = find(node1);
        int parentOfNode2 = find(node2);
        
        if(parentOfNode1 == parentOfNode2) return;
        
        if(parent[parentOfNode1] <= parent[parentOfNode2]) {
            parent[parentOfNode1] += parent[parentOfNode2];
            parent[parentOfNode2] = parentOfNode1;
        }
        else {
            parent[parentOfNode2] += parent[parentOfNode1];
            parent[parentOfNode1] = parentOfNode2;
        }
    }

    int countCycles(int n, vector<vector<int>> &type1Ortype2, vector<vector<int>> &type3) {
        int count = 0;
        parent = vector<int>(n+1,-1);
        
        for(int i=0;i<type3.size();i++) {
            doUnion(type3[i][1], type3[i][2]);
        }
        
        for(int i=0;i<type1Ortype2.size();i++) {
            if(find(type1Ortype2[i][1]) == find(type1Ortype2[i][2])) count++;
            else doUnion(type1Ortype2[i][1], type1Ortype2[i][2]);
        }
        
        return count;
    }
    
    vector<vector<int>> removeCycles(int n, vector<vector<int>> &edges, int &count) {
        parent = vector<int>(n+1,-1);
        vector<vector<int>> result;
        
        for(int i=0;i<edges.size();i++) {
            if(find(edges[i][1]) == find(edges[i][2])) {
                count++;
            }
            else {
                doUnion(edges[i][1], edges[i][2]);
                result.push_back(edges[i]);
            }
        }

        return result;
    }
    
    bool canReachAllNodes(int n) {
        int count = 0;
        for(int i=1;i<=n;i++) {
            if(parent[i] < 0) count++;
        }
        
        return count == 1;
    }
    
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> type1, type2, type3;
    
        for(int i=0;i<edges.size();i++) {
            if(edges[i][0] == 1) type1.push_back(edges[i]);
            else if(edges[i][0] == 2) type2.push_back(edges[i]);
            else type3.push_back(edges[i]);
         }
        
        type3 = removeCycles(n, type3, ans);
        
        ans += countCycles(n,type1, type3);
        if(!canReachAllNodes(n)) return -1; 
        ans += countCycles(n,type2, type3);
        if(!canReachAllNodes(n)) return -1; 
        return ans;
    }
};
