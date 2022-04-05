class Solution {
public:
    int solve(int idx, vector<int> &nums, int curSum, int target, unordered_map<int,unordered_map<int,int>> &visited) {
        if(idx == nums.size()) {
            if(curSum == target) return 1;
            return 0;
        }
        
        if(visited.find(idx) != visited.end()
           && visited[idx].find(curSum) != visited[idx].end()) {
            return visited[idx][curSum];
        }
        
        visited[idx][curSum] += solve(idx+1, nums, curSum + nums[idx], target, visited);
        visited[idx][curSum] += solve(idx+1, nums, curSum - nums[idx], target, visited);
        
        return visited[idx][curSum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>> visited;
        return solve(0, nums, 0, target, visited);
    }
};