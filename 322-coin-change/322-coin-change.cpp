class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=0;i<coins.size();i++) {
            for(int j=1;j<=amount;j++) {
                int value = j-coins[i];
                if(value >= 0 && dp[value] != INT_MAX) {
                    dp[j] = min(dp[j], dp[value]+1);
                }
            }
        }
        
        if(dp[amount] == INT_MAX) dp[amount] = -1;
        
        return dp[amount];
    }
};