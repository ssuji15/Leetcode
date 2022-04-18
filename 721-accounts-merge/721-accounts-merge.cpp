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
    
    void doJoin(int node1, int node2) {
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
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,int> accountIdx;
        parent = vector<int>(accounts.size(), -1);

        for(int i=0;i<accounts.size();i++) {
            for(int j=1;j<accounts[i].size();j++) {
                if(accountIdx.find(accounts[i][j]) == accountIdx.end()) {
                    accountIdx[accounts[i][j]] = i;
                }
                else {
                    doJoin(accountIdx[accounts[i][j]],i);
                }
            }
        }
        
        vector<set<string>> mergeAccounts(accounts.size());
        
        for(int i=0;i<accounts.size();i++) {
            for(int j=1;j<accounts[i].size();j++) {
                mergeAccounts[find(accountIdx[accounts[i][j]])].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for(int i=0;i<accounts.size();i++) {
            if(mergeAccounts[i].size() > 0) {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto word: mergeAccounts[i]) {
                    temp.push_back(word);
                }
                result.push_back(temp);
            }
        }
        
        return result;
        
        
    }
};
