class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curSum = 0, maxSum = INT_MIN;
        
        for(int i=0;i<nums.size();i++) {
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;

    }
};