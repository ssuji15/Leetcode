class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int start = 0, end = nums.size()-1;
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            
            bool left = true, right = true;
            if(mid-1 >= 0 && nums[mid] < nums[mid-1]) {
                left = false;
            }
            
            if(mid+1 < nums.size() && nums[mid] < nums[mid+1]) {
                right = false;
            }
            
            if(left && right) return mid;
            
            if(!left) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
};
