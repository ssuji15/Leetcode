class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0, subSetSum = 0;
        
        for(int i=0;i<nums.size();i++) {
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        subSetSum = totalSum / 2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(subSetSum+1, false)); 
        dp[0][0] = true;
        for(int i=1;i<=nums.size();i++) {
            int curElement = nums[i-1];
            for(int j=0;j<=subSetSum;j++) {
                if(j<curElement) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-curElement];
            }
        }
        return dp[nums.size()][subSetSum];
    }
};