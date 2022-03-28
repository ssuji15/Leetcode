class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adjacentString;
        unordered_map<string,bool> visited;
        for(int i=0;i<wordList.size();i++) {
            for(int j=0;j<wordList[i].length();j++) {
                string newWord = wordList[i].substr(0, j) + "*" + wordList[i].substr(j+1);
                adjacentString[newWord].push_back(wordList[i]);
            }
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        visited[beginWord] = true;
        while(!q.empty()) {
            string cur = q.front().first;
            int length = q.front().second;
            q.pop();
            for(int j=0;j<cur.length();j++) {
                string newWord = cur.substr(0, j) + "*" +cur.substr(j+1);
                for(int i=0;i<adjacentString[newWord].size();i++) {
                    string newCur = adjacentString[newWord][i];
                    if(newCur.compare(endWord) == 0) return length+1;
                    if(visited.find(newCur) == visited.end()) {
                        visited[newCur] = true;
                        q.push({newCur, length+1});
                    }
                }
            }
        }
        return 0;
    }
};