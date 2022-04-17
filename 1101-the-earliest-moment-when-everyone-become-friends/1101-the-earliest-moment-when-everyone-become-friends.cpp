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
    
    int doUnion(int node1, int node2) {
        int parentNode1 = find(node1);
        int parentNode2 = find(node2);
        
        if(parentNode1 == parentNode2) return -1;
        
        if(parent[parentNode1] <= parent[parentNode2]) {
            parent[parentNode1] += parent[parentNode2];
            parent[parentNode2] = parentNode1;
            return parentNode1;
        }
        else {
            parent[parentNode2] += parent[parentNode1];
            parent[parentNode1] = parentNode2;
            return parentNode2;
        }
        return -1;
    }
    
    struct MyComparator {
      public:
        bool operator()(vector<int> &A, vector<int> &B) {
            return A[0] > B[0];
        }
    };
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent = vector<int>(n, -1);
        
        priority_queue<vector<int>, vector<vector<int>>, MyComparator> pq;
        
        for(int i=0;i<logs.size();i++) {
            pq.push(logs[i]);
        }
        
        while(!pq.empty()) {
            vector<int> log = pq.top();
            pq.pop();
            
            int curParent = doUnion(log[1], log[2]);
            if(curParent != -1 && abs(parent[curParent]) == n) {
                return log[0];
            }
        }
        return -1;
    }
};