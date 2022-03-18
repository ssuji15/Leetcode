class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int cost1 = INT_MAX, cost2 = INT_MAX, color1, color2;
        for(int i=0;i<costs[0].size();i++) {
            if(costs[0][i] < cost1) {
                cost2 = cost1;
                color2 = color1;
                cost1 = costs[0][i];
                color1 = i;
            }
            else if(costs[0][i] < cost2) {
                cost2 = costs[0][i];
                color2 = i;
            }
        }
        
        for(int i=1;i<costs.size();i++) {
            int newCost1 = INT_MAX, newCost2 = INT_MAX, newColor1, newColor2;
            for(int j=0;j<costs[0].size();j++) {
                int temp;
                if(color1 == j) {
                    temp = costs[i][j] + cost2;
                }
                else {
                    temp = costs[i][j] + cost1;
                }
                if(temp < newCost1) {
                    newCost2 = newCost1;
                    newColor2 = newColor1;
                    newCost1 = temp;
                    newColor1 = j;
                }
                else if(temp < newCost2) {
                    newCost2 = temp;
                    newColor2 = j;
                }
            }
            cost1 = newCost1;
            cost2 = newCost2;
            color1 = newColor1;
            color2 = newColor2;
        }
        return cost1;
    }
};