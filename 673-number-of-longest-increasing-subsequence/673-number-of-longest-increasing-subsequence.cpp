class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> length(nums.size(),1);
        vector<int> count(nums.size(),1);
        int longest = 1, ans = 0;
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]) {
                    if(length[j]+1 > length[i]) {
                        length[i] = length[j]+1;
                        count[i] = count[j];
                    }
                    else if(length[i] == length[j]+1) {
                        count[i] += count[j];
                    }
                }
            }
            longest = max(longest, length[i]);
        }
        for(int i=0;i<nums.size();i++) {
            if(length[i] == longest) ans += count[i];
        }
        return ans;
    }
};