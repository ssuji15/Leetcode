using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        bool foundOne = false;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                dp[i][j] = matrix[i][j] - '0';
                if(dp[i][j] == 1) foundOne = true;
            }
        }
        int size = 0;
        for(int i=1;i<matrix.size();i++) {
            for(int j=1;j<matrix[0].size();j++) {
                if(dp[i][j] == 1) {
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
                }
                size = max(size, dp[i][j]);
            }
        }
        if(size == 0 && foundOne) return 1;
        return size * size;
    }
};