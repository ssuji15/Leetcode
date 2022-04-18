class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int ans = -1;
        set<int> cache;
        cache.insert(nums[0]);
        
        for(int i=1;i<nums.size();i++) {
            auto itr = cache.lower_bound(k-nums[i]);
            if(itr != cache.begin()) {
                itr--;
                int value = *itr + nums[i];
                
                if(value < k) {
                    ans = max(ans, value);
                }
            }
            cache.insert(nums[i]);
        }
        
        return ans;
    }
};