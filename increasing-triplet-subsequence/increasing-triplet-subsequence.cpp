class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX, secondNum = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] <= firstNum) {
                firstNum = nums[i];
            }
            else if(nums[i] <= secondNum) {
                secondNum = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};