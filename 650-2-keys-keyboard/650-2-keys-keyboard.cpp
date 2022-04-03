class Solution {
public:
    unordered_map<int,int> dp;
    int minSteps(int n) {
        if(n==1) return 0;
        if(dp.find(n) != dp.end()) {
            return dp[n];
        }
        dp[n] = n;
        //int val = ceil(sqrt(n));
        for(int i=2;i<n;i++) {
            if(n%i == 0) {
                dp[n] = min(dp[n], minSteps(i) + n/i);
            }
        }
        return dp[n];
    }
};