class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool> deadEndCache;
        unordered_map<string,int> processedCache;
        for(int i=0;i<deadends.size();i++) {
            deadEndCache[deadends[i]] = true;
        }
        int ans = INT_MAX;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()) {
            string cur = q.front().first;
            int curDistance = q.front().second;
            q.pop();
            
            if(deadEndCache.find(cur) != deadEndCache.end()) {
                continue;
            }
            
            if(cur.compare(target) == 0) {
                ans = min(ans, curDistance);
                continue;
            }

            for(int i=0;i<4;i++) {
                string temp = cur;
                if(temp[i] == '0') {
                    temp[i] = '9';
                }
                else {
                    temp[i] = temp[i]-1;
                }
                
                if(processedCache.find(temp) == processedCache.end() || processedCache[temp] > curDistance+1) {
                    processedCache[temp] = curDistance + 1;
                    q.push({temp,curDistance+1});
                }
                
                temp = cur;
                if(temp[i] == '9') {
                    temp[i] = '0';
                }
                else {
                    temp[i] = temp[i]+1;
                }
                
                if(processedCache.find(temp) == processedCache.end() || processedCache[temp] > curDistance+1) {
                    processedCache[temp] = curDistance + 1;
                    q.push({temp,curDistance+1});
                }
            } 
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};