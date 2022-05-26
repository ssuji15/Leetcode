class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> cache;
        for(int i=0;i<nums.size();i++) {
            int secondNum = target-nums[i];
            if(cache.find(secondNum) != cache.end()) {
                return {cache[secondNum], i};
            }
            cache[nums[i]] = i;
        }
        return {-1,-1};
    }
};