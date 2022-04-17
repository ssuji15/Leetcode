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
        
        if(parentNode1 < parentNode2) {
            parent[parentNode2] = parentNode1;
        }
        else {
            parent[parentNode1] = parentNode2;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent = vector<int>(26,-1);
        
        for(int i=0;i<s1.length();i++) {
            doUnion(s1[i]-'a', s2[i]-'a');
        }
        
        string result = "";
        for(int i=0;i<baseStr.length();i++) {
            int curChar = find(baseStr[i]-'a');
            result += curChar+'a';
        }
        
        return result;
        
    }
};