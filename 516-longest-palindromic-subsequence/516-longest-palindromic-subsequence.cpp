class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 1));
        int n = s.length(), ans = 1;
        
        for(int i=1;i<s.length();i++) {
            for(int j=0;j+i<s.length();j++) {
                if(i==1) {
                    dp[j][j+i] =  s[j] == s[j+i] ? 2 : 1;
                }
                else {
                    dp[j][j+i] = s[j] == 
                        s[j+i] ? 2 + dp[j+1][j+i-1] 
                        : max(dp[j][j+i-1], dp[j+1][j+i]);
                }
                ans = max(ans, dp[j][j+i]);
            }
        }
        return ans;
    }
};