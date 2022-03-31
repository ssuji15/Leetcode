class Solution {
public:
    // 0: left
    // 1: up
    // 2: left Diag
    // 3: right Diag
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(4,0));
        for(int i=0;i<m;i++) {
            vector<vector<int>> temp(n, vector<int>(4,0));
            for(int j=0;j<n;j++) {
               if(mat[i][j] == 0) {
                   continue;
               } else {
                   temp[j][0] = j-1 >= 0 ? temp[j-1][0] + 1 : 1;
                   temp[j][1] = dp[j][1] + 1;
                   temp[j][2] = j-1 >= 0 ? dp[j-1][2] + 1 : 1;
                   temp[j][3] = j+1 < n ? dp[j+1][3] + 1 : 1;
               }
                for(int k=0;k<4;k++) {
                    ans = max(ans, temp[j][k]);
                }
            }
            dp = temp;
        }
        return ans;
    }
};