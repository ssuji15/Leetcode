class Solution {
public:
    vector<int> parent;
    unordered_map<int, string> indexToWordMap;
    unordered_map<string, int> wordToIndexMap;
    
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
        
        if(indexToWordMap[node1].compare(indexToWordMap[node2]) < 0) {
            parent[parentNode1] += parent[parentNode2];
            parent[parentNode2] = parentNode1;
        }
        else {
            parent[parentNode2] += parent[parentNode1];
            parent[parentNode1] = parentNode2;
        }
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        
        int count = 0;
        parent = vector<int>(synonyms.size()*2, -1);
        set<string> words;
        
        for(int i=0;i<synonyms.size();i++) {
            if(wordToIndexMap.find(synonyms[i][0]) == wordToIndexMap.end()) {
                wordToIndexMap[synonyms[i][0]] = count;
                indexToWordMap[count] = synonyms[i][0];
                count++;
                words.insert(synonyms[i][0]);
            }
            
            if(wordToIndexMap.find(synonyms[i][1]) == wordToIndexMap.end()) {
                wordToIndexMap[synonyms[i][1]] = count;
                indexToWordMap[count] = synonyms[i][1];
                count++;
                words.insert(synonyms[i][1]);
            }
            
            doUnion(wordToIndexMap[synonyms[i][0]],wordToIndexMap[synonyms[i][1]]);
        }
        
        vector<vector<string>> res;
        string curWord = "";
        vector<string> temp;
        for(int i=0;i<text.length();i++) {
            if(text[i] == ' ') {
                temp.push_back(curWord);
                curWord = "";
            }
            else {
                curWord += text[i];
            }
        }
        temp.push_back(curWord);
        res.push_back(temp);
        
        for(int i=0;i<temp.size();i++) {
            for(auto word: words) {
                if(wordToIndexMap.find(temp[i]) != wordToIndexMap.end()
                                       && find(wordToIndexMap[word]) 
                                       ==find(wordToIndexMap[temp[i]])
                  && word.compare(temp[i]) != 0) {
                    int size = res.size();
                    for(int j=0;j<size;j++) {
                        vector<string> sentence = res[j];
                        sentence[i] = word;
                        res.push_back(sentence);
                    }
                }
            }
        }
        
        set<string> result;
        for(auto sentence: res) {
            string temp = "";
            for(int i=0;i<sentence.size();i++) {
                temp += sentence[i];
                if(i != sentence.size() - 1) temp += " ";
            }
            result.insert(temp);
        }
        
        vector<string> ans(result.begin(), result.end());
        
        return ans;
    }
};