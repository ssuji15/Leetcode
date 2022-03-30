class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> lengths(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        int ans = 1, n= nums.size(), ansIdx = -1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0) {
                    if(1+lengths[j] > lengths[i]) {
                        lengths[i] = 1 + lengths[j];
                        prev[i] = j;
                        if(lengths[i] > ans) {
                            ans = lengths[i];
                            ansIdx = i;
                        }
                    }
                }
            }
        }

        vector<int> result;
        if(ansIdx == -1) {
            return {nums[0]};
        }
        while(ansIdx != -1) {
            result.push_back(nums[ansIdx]);
            ansIdx = prev[ansIdx];
        }
        return result;
    }
};