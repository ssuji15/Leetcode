class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for(int i=3;i<=n;i++) {
            int ans = INT_MIN;
            for(int k=1;k<i;k++) {
                ans = max(ans, max(k*(i-k),k * dp[i-k]));
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};