class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int length = 1, total = 1;
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            if(dp[i] == length) total += count[i];
            else if(dp[i] > length) {
                length = dp[i];
                total = count[i];
            }
        }
        return total;
    }
};