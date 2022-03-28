class Solution {
public:
    vector<char> choices = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,bool> bankMap;
        unordered_map<string,bool> visited;
        for(int i=0;i<bank.size();i++) {
            bankMap[bank[i]] = true;
        }
        
        queue<pair<string,int>> q;
        q.push({start,0});
        visited[start] = true;
        while(!q.empty()) {
            string cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(int i=0;i<cur.length();i++) {
                for(int j=0;j<choices.size();j++) {
                    string temp(cur);
                    if(cur[i] != choices[j]) {
                        temp[i] = choices[j];
                        if(bankMap.find(temp) != bankMap.end()) {
                            if(temp.compare(end) == 0) return steps + 1;
                            if(visited.find(temp) == visited.end()) {
                                visited[temp] = true;
                                q.push({temp, steps + 1});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};