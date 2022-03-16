class Solution {
public:
    vector<int> minCost;
    int solve(int idx, vector<int> &cost) {
        if(idx <= 1) {
            return cost[idx];
        }
        if(minCost[idx] != INT_MAX) {
            return minCost[idx];
        }
        
        minCost[idx] = cost[idx] + min(solve(idx-1, cost), solve(idx-2, cost));
        return minCost[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        minCost = vector<int>(cost.size(), INT_MAX);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        solve(cost.size()-1, cost);
        return min(minCost[cost.size()-1], minCost[cost.size()-2]);
    }
};