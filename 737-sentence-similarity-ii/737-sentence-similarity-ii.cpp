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
    
    
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        if(sentence1.size() != sentence2.size()) return false;
        
        unordered_map<string,int> wordMap;
        int count = 0;
        parent = vector<int>(similarPairs.size()*2, -1);
        for(int i=0;i<similarPairs.size();i++) {
            if(wordMap.find(similarPairs[i][0]) == wordMap.end()) {
                wordMap[similarPairs[i][0]] = count;
                count++;
            }
            
            if(wordMap.find(similarPairs[i][1]) == wordMap.end()) {
                wordMap[similarPairs[i][1]] = count;
                count++;
            }
            
            doUnion(wordMap[similarPairs[i][0]], wordMap[similarPairs[i][1]]);
        }
        
        for(int i=0;i<sentence1.size();i++) {
            if(sentence1[i].compare(sentence2[i]) != 0 && (wordMap.find(sentence1[i]) == wordMap.end() || wordMap.find(sentence2[i]) == wordMap.end() || find(wordMap[sentence1[i]]) != find(wordMap[sentence2[i]]))) {
                return false;
            }
        }
        
        return true;
    }
};