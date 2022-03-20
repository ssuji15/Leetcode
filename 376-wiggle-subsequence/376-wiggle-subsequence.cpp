class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        vector<vector<int>> dp(nums.size(), vector<int>(2,1));
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                int diff = nums[i] - nums[j];
                if(diff < 0) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                    ans = max(ans, dp[i][0]);
                }
                else if(diff > 0) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                    ans = max(ans, dp[i][1]);
                }
            }
        }
        return ans;
    }
};