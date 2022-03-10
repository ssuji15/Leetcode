class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), INT_MAX));
        if(dungeon[dungeon.size()-1][dungeon[0].size()-1] < 0) {
            dungeon[dungeon.size()-1][dungeon[0].size()-1]--;
        }
        for(int i=dungeon.size()-1;i>=0;i--) {
            for(int j=dungeon[0].size()-1;j>=0;j--) {
                
                int value1 = INT_MAX;
                int value2 = INT_MAX;

                if(i+1 < dungeon.size()) {
                    value1 = dp[i+1][j];
                }

                if(j+1 < dungeon[0].size()) {
                    value2 = dp[i][j+1];
                }
                int minVal = min(value1, value2);
                if(dungeon[i][j] < 0) {
                    dp[i][j] = dungeon[i][j] * -1;
                    if(minVal != INT_MAX) {
                        dp[i][j] += minVal;
                    }
                }
                else {
                    if(minVal == INT_MAX || dungeon[i][j] >= minVal) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = minVal-dungeon[i][j];
                    }
                }
            }
        }
        return dp[0][0];
    }
};