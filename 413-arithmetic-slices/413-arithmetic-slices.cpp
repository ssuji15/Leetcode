class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0, prev = 0;
        for(int i=2;i<nums.size();i++) {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2]) {
                prev++;
                result += prev;
                
            }
            else {
                prev = 0;
            }
        }
        return result;
    }
};