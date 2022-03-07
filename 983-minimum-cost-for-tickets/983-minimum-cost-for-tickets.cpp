class Solution {
public:
    int findCost(int idx, vector<int> &days, vector<int> &costs, vector<int> &cache,
                int pass) {
        if(idx == days.size()) return 0;
        
        if(days[idx] <= pass) {
            return findCost(idx+1, days, costs, cache, pass);
        }
        
        if(cache[idx] != -1) {
            return cache[idx];
        }
        int cost1 = costs[0] + findCost(idx+1, days, costs, cache, -1);
        int cost2 = costs[1] + findCost(idx+1, days, costs, cache, days[idx]+7-1);
        int cost3 = costs[2] + findCost(idx+1, days, costs, cache, days[idx]+30-1);
        int cost = min(cost1, min(cost2,cost3));
        cache[idx] = cost;
        return cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cache(days.size(), -1);
        return findCost(0,days,costs,cache,-1);
    }
};