class Solution {
public:
    void travel(string curCity, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adjacent,vector<string> &result) {
        while(!adjacent[curCity].empty()) {
            string newCity = adjacent[curCity].top();
            adjacent[curCity].pop();
            travel(newCity, adjacent, result);
        }
        result.push_back(curCity);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adjacent;
        
        for(int i=0;i<tickets.size();i++) {
            adjacent[tickets[i][0]].push(tickets[i][1]);
        }
        
        vector<string> result;
        travel("JFK", adjacent, result);
        reverse(result.begin(), result.end());
        return result;
        
    }
};