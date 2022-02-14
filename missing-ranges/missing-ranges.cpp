class Solution {
public:
    void addString(long long start, long long end, vector<string> &result) {
        if(start == end) {
            result.push_back(to_string(start));
        }
        else {
            result.push_back(to_string(start) + "->" + to_string(end));
        }
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        
        if(nums.size() == 0) {
            addString(lower,upper,result);
            return result;
        }
        
        
        if(nums[0] != lower) {
            long long start = lower;
            long long end = nums[0]-1;
            addString(lower,nums[0]-1, result);
        }
        
        long long prev = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(prev + 1 != nums[i]) {
                addString(prev + 1L, nums[i]-1L, result);
            }
            prev = nums[i];
        }
        
        if(prev != upper) {
            addString(prev+1L, upper, result);
        }
        
        return result;
    }
};