class Solution {
public:
    unordered_map<int,unordered_map<int,int>> cache;
    int PredictTheWinner(vector<int>& nums, int start, int end) {
        if(start == end) {
            return nums[start];
        }
        
        if(cache.find(start) != cache.end() && cache[start].find(end) != cache[start].end()) {
            return cache[start][end];
        }
        
        int a = nums[start] - PredictTheWinner(nums,start+1,end);
        int b = nums[end] - PredictTheWinner(nums,start,end-1);
        cache[start][end] = max(a,b);
        return cache[start][end];
    }
    bool PredictTheWinner(vector<int>& nums) {
        return PredictTheWinner(nums,0,nums.size()-1) >= 0;
    }
};
