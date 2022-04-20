class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        if(itr == nums.end() || *itr != target) return false;
        int endIdx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return (endIdx - (itr-nums.begin())) + 1 > nums.size() / 2;
    }
};