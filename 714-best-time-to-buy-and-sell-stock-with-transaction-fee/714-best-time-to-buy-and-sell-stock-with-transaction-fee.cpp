class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxWith0 = 0, maxWith1 = -prices[0]-fee;
        for(int i=1;i<prices.size();i++) {
            maxWith0 = max(maxWith0, maxWith1+prices[i]);
            maxWith1 = max(maxWith1, maxWith0-prices[i]-fee);
        }
        return maxWith0;
    }
};