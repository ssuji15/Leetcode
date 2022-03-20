class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        if(ans == -1) ans = nums.size();
        return ans;
    }
};