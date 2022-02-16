class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int i;
        for(i=1;i<nums.size();i++) {
            if(nums[i]-nums[i-1]-1 >= k) {
                break;
            }
            else {
                k = k-(nums[i]-nums[i-1]-1);
            }
        }
        return nums[i-1]+k;
    }
};