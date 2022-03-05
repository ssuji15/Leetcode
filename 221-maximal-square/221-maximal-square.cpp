class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == '0') {
                    continue;
                }
                int value1 = 0, value2 = 0, value3 = 0;
                if(i-1 >= 0) {
                    value1 = dp[i-1][j];
                }
                if(j-1 >= 0) {
                    value2 = dp[i][j-1];
                }
                if(i-1>=0 && j-1>=0) {
                    value3 = dp[i-1][j-1];
                }
                dp[i][j] = min(value1, min(value2,value3)) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};