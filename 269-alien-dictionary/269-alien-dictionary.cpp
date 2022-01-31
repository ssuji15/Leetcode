struct Node {
    char x;
    int incomingEdgeCount;
    vector<char> outGoingNodes;
    Node(char ch) {
        this->x = ch;
        incomingEdgeCount = 0;
        outGoingNodes = {};
    }
};
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, Node*> chars;
        
        for(int i=0;i<words.size();i++) {
            for(int j=0;j<words[i].length();j++) {
                if(chars.find(words[i][j]) == chars.end()) {
                    chars[words[i][j]] = new Node(words[i][j]);
                }
            }
        }
        
        for(int i=0;i<words.size()-1;i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            
            int j;
            
            for(j=0;j<word1.length() && j<word2.length();j++) {
                if(word1[j] != word2[j]) {
                    chars[word1[j]]->outGoingNodes.push_back(word2[j]);
                    chars[word2[j]]->incomingEdgeCount++;
                    break;
                }
            }
            
            if(j!=word1.length() && j==word2.length()) {
                return "";
            }
        }
        
        queue<char> q;
        
        for(int i=0;i<26;i++) {
            if(chars.find(i+'a') != chars.end() && chars[i+'a']->incomingEdgeCount == 0) {
                q.push(i+'a');
            }
        }
        
        string res = "";
        
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            
            res += cur;
            
            for(int i=0;i<chars[cur]->outGoingNodes.size();i++) {
                chars[chars[cur]->outGoingNodes[i]]->incomingEdgeCount--;
                if(chars[chars[cur]->outGoingNodes[i]]->incomingEdgeCount == 0) {
                    q.push(chars[cur]->outGoingNodes[i]);
                }
            }
        }
        
        if(res.length() == chars.size()) {
            return res;
        }
        return "";
        
    }
};