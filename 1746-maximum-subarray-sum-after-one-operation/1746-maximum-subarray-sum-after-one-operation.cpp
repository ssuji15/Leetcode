class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int withOutSquare = nums[0], withSquare = nums[0] * nums[0], result = withSquare;
        
        for(int i=1;i<nums.size();i++) {
            int temp = withOutSquare;
            withOutSquare = max(nums[i], withOutSquare + nums[i]);
            withSquare = max(nums[i] * nums[i], max(withSquare + nums[i], temp + nums[i]*nums[i]));
            result = max(withSquare, result);
        }
        return result;
    }
};