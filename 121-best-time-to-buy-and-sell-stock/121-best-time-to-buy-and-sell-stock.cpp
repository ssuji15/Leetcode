class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MIN, minNumber = prices[0];
        for(int i=1;i<prices.size();i++) {
            cost = max(cost, prices[i]-minNumber);
            minNumber = min(minNumber, prices[i]);
        }
        return max(0,cost);
    }
};