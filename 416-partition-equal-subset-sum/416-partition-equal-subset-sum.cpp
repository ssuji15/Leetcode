class Solution {
public:
    bool dfs(int idx, int targetSum, vector<int> &nums, unordered_map<int,unordered_map<int,int>> &cache) {
        if(idx == nums.size() || targetSum < 0) return false;
        
        if(targetSum == 0) return true;
        
        if(cache.find(idx) != cache.end() && cache[idx].find(targetSum) != cache[idx].end()) {
            return cache[idx][targetSum];
        }
        
        cache[idx][targetSum] = dfs(idx+1, targetSum-nums[idx], nums, cache) || dfs(idx+1, targetSum, nums, cache);
        
        return cache[idx][targetSum];
    }
    bool canPartition(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>> cache;
        int targetSum = 0, sum = 0;
        
        for(int i=0;i<nums.size();i++) {
            targetSum += nums[i];
        }
        
        if(targetSum % 2 != 0) return false;
        
        targetSum = targetSum / 2;
        
        return dfs(0,targetSum,nums,cache);
    }
};


