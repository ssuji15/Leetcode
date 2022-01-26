class Solution {
public:
    int findBound(int start, int end, vector<int> &nums, int target, bool lowerBound) {
        int idx = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) {
                idx = mid;
                if(lowerBound) {
                    end = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int start = 0, end = nums.size()-1, startIdx = -1, endIdx = -1;
        startIdx = findBound(0,nums.size()-1,nums, target, true);

        if(startIdx == -1) {
            return {-1, -1};
        }
        
        endIdx = findBound(startIdx, nums.size()-1, nums, target, false);
        return {startIdx, endIdx};
    }
};