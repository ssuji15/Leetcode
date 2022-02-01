class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = 0;

        for(int i=0;i<intervals.size();i++) {
            pq.push({intervals[i][0], 1});
            pq.push({intervals[i][1], -1});
        }
        
        int curRooms = 0;
        while(!pq.empty()) {
            vector<int> temp = pq.top();
            pq.pop();
            
            curRooms += temp[1];
            ans = max(ans, curRooms);
        }
        
        return ans;
    }
};