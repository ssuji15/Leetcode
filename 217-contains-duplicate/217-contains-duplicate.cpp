class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> cache;
        for(int i=0;i<nums.size();i++) {
            if(cache.find(nums[i]) != cache.end()) return true;
            cache[nums[i]] = true;
        }
        return false;
    }
};