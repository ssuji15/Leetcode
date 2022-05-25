class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto x = lower_bound(nums.begin(), nums.end(), target);
        if(x == nums.end() || *x != target) return -1;
        return x-nums.begin();
    }
};