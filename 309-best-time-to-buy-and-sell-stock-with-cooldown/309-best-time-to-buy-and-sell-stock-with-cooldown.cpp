class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxWith0 = 0, maxWith1 = -prices[0], maxWithPrev0 = 0;
        for(int i=1;i<prices.size();i++) {
            int temp = maxWith0;
            maxWith0 = max(maxWith0, maxWith1+prices[i]);
            maxWith1 = max(maxWith1, maxWithPrev0 - prices[i]);
            maxWithPrev0 = temp;
        }
        return maxWith0;
    }
};