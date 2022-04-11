class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, maxReach = nums[0], ans = 0;
        for(int i=1;i<nums.size();i++) {
            if(count == 0) {
                count = maxReach - i + 1;
                ans++;
            }
            count--;
            maxReach = max(maxReach, i + nums[i]);
        }
        return ans;
    }
};