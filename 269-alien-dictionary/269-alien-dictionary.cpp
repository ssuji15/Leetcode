class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,bool> isPresent;
        vector<char> allChars;
        for(int i=0;i<words.size();i++) {
            for(int j=0;j<words[i].length();j++) {
                if(isPresent.find(words[i][j]) == isPresent.end()) {
                    allChars.push_back(words[i][j]);
                    isPresent[words[i][j]] = true;
                }
            }
        }
        
        unordered_map<char,vector<char>> adjacentNodes;
        unordered_map<char,int> incomingEdges;
        for(int i=1;i<words.size();i++) {
            string word1 = words[i-1];
            string word2 = words[i];
            if(word1.compare(word2) == 0) continue;
            bool notChanged = true;
            for(int j=0;j<word1.length() && j<word2.length(); j++) {
                if(word1[j] == word2[j]) continue;
                adjacentNodes[word1[j]].push_back(word2[j]);
                incomingEdges[word2[j]]++;
                notChanged = false;
                break;
            }
            if(notChanged && word1.length() > word2.length()) return "";
        }
        
        queue<char> q;
        string res = "";
        for(int i=0;i<allChars.size();i++) {
            if(incomingEdges[allChars[i]] == 0) {
                q.push(allChars[i]);
            }
        }
        while(!q.empty()) {
            char ch = q.front();
            q.pop();
            res += ch;
            for(int i=0;i<adjacentNodes[ch].size();i++) {
                char newCh = adjacentNodes[ch][i];
                incomingEdges[newCh]--;
                if(incomingEdges[newCh] == 0) {
                    q.push(newCh);
                }
            }
        }
        if(res.length() != allChars.size()) {
            return "";
        }
        return res;
    }
};
