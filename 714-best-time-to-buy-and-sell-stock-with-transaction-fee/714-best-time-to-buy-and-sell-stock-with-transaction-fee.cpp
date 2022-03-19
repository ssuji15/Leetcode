class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int withOneStock = -prices[0]-fee, withZeroStock = 0;
        for(int i=1;i<prices.size();i++) {
            withZeroStock = max(withZeroStock, prices[i] + withOneStock);
            withOneStock = max(withOneStock, withZeroStock + (-prices[i] - fee));
        }
        return withZeroStock;
    }
};