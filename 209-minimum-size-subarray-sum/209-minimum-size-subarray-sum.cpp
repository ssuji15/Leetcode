class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, curSum=0,i,j;
        for(i=0,j=0;i<nums.size();i++) {
            curSum += nums[i];
            while(j<=i && curSum >= target) {
                ans = min(ans, (i-j+1));
                curSum -= nums[j];
                j++;
            }
        }
        while(j<=i && curSum >= target) {
            ans = min(ans, (i-j+1));
            curSum -= nums[j];
            j++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};