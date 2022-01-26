class Solution {
public:

    int binarySearch(int start, int end, vector<int> &nums, int target) {

        if(start > end) return -1;
        
        int mid = start + (end - start) / 2;
        
        if(nums[mid] == target) return mid;
        
        if(nums[start] <= nums[mid]) {
            
            if(target < nums[mid] && target >= nums[start]) {
                return binarySearch(start,mid-1, nums, target);
            }
            else {
                return binarySearch(mid+1, end, nums, target);
            }
        }
        else {
            
            if(target <= nums[end] && target > nums[mid]) {
                return binarySearch(mid+1, end, nums, target);
            }
            else {
                return binarySearch(start, mid-1, nums, target);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};