class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> withOneStock(prices.size(), 0);
        vector<int> withZeroStock(prices.size(), 0);
        withOneStock[0] = -prices[0];
        for(int i=1;i<prices.size();i++) {
            withZeroStock[i] = max(withZeroStock[i-1], prices[i] + withOneStock[i-1]);
            withOneStock[i] = max(withOneStock[i-1], i-2 >= 0 ? withZeroStock[i-2]-prices[i] : 0-prices[i]);
        }
        return withZeroStock[prices.size()-1];
    }
};