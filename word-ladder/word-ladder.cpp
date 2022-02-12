class Solution {
public:
    
    bool differByOne(string &a, string &b) {
        bool differ = false;
        for(int i=0;i<a.length();i++) {
            if(a[i] != b[i]) {
                if(differ) return false;
                differ = true;
            }
        }
        return differ;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> distance;
        for(int i=0;i<wordList.size();i++) {
            distance[wordList[i]] = INT_MAX;
        }
        distance[beginWord] = 1;
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            string str = q.front();
            q.pop();
            
            if(str == endWord) continue;
            
            for(int i=0;i<wordList.size();i++) {
                if(differByOne(str, wordList[i]) && distance[wordList[i]] > distance[str]+1) {
                    distance[wordList[i]] = distance[str]+1;
                    q.push(wordList[i]);
                }
            }
        }
        if(distance[endWord] == INT_MAX) distance[endWord] = 0;
        return distance[endWord];
    }
};