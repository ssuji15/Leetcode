class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target.compare("0000") == 0) return 0;
        unordered_map<string, bool> deadMap;
        unordered_map<string, bool> visited;
        for(int i=0;i<deadends.size();i++) {
            deadMap[deadends[i]] = true;
        }
        queue<pair<string,int>> q;
        q.push({"0000", 0});
        visited["0000"] = true;
        
        while(!q.empty()) {
            string cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(deadMap.find(cur) != deadMap.end()) continue;
            
            for(int i=0;i<cur.length();i++) {
                string temp1(cur);
                string temp2(cur);
                if(temp1[i] == '0') { temp1[i] = '9';}
                else temp1[i]--;
                
                if(temp2[i] == '9') { temp2[i] = '0';}
                else temp2[i]++;
                
                if(temp1.compare(target) == 0 || temp2.compare(target) == 0) return steps+1;
                
                if(visited.find(temp1) == visited.end()) {
                    visited[temp1] = true;
                    q.push({temp1, steps+1});
                }
                if(visited.find(temp2) == visited.end()) {
                    visited[temp2] = true;
                    q.push({temp2, steps+1});
                }
            }
        }
        return -1;
    }
};