class Solution {
public:
    int search(int start, int end, vector<int> &nums, int target) {
        if(start > end) return -1;
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid;
        
        if(nums[start] <= nums[mid]) {
            if(target >= nums[start] && target <= nums[mid]) {
                return search(start, mid-1, nums, target);
            }
            else {
                return search(mid+1, end, nums, target);
            }
        }
        else {
            if(target >= nums[mid] && target <= nums[end]) {
                return search(mid+1, end, nums, target);
            }
            else {
                return search(start, mid-1, nums, target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return search(0, nums.size()-1, nums, target);
    }
};