class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int val = nums.size() + 2;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] <= 0) nums[i] = val++;
        }
        
        for(int i=0;i<nums.size();i++) {
            int val = abs(nums[i])-1;
            if(val >= 0 && val < nums.size() && nums[val] > 0) {
                nums[val] = nums[val] * -1;
            }
        }
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > 0) {
                return i+1;
            }
        }
        
        return nums.size()+1;
    }
};