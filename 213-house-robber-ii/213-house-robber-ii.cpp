class Solution {
public:
    int robHouses(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        int max2 = nums[nums.size()-1];
        int max1 = max(max2, nums[nums.size()-2]);
        for(int i=nums.size()-3;i>=0;i--) {
            int cur = max(nums[i] + max2, max1);
            max2 = max1;
            max1 = cur;
        }
        return max(max1, max2);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int temp = nums[0];
        nums[0] = 0;
        int ans1 = robHouses(nums);
        nums[0] = temp;
        nums[nums.size()-1] = 0;
        int ans2 = robHouses(nums);
        return max(ans1, ans2);
    }
};