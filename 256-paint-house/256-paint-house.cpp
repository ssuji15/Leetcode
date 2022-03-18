class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int cost1 = costs[0][0];
        int cost2 = costs[0][1];
        int cost3 = costs[0][2];
        
        for(int i=1;i<costs.size();i++) {
            int temp1 = costs[i][0] + min(cost2, cost3);
            int temp2 = costs[i][1] + min(cost1, cost3);
            int temp3 = costs[i][2] + min(cost1, cost2);
            cost1 = temp1;
            cost2 = temp2;
            cost3 = temp3;
        }
        return min(cost1, min(cost2, cost3));
    }
};