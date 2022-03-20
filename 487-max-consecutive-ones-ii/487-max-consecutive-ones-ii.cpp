class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool flipped = false;
        int start = 0, ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                if(!flipped) {
                    flipped = true;
                }
                else {
                    while(start < i && nums[start] != 0) start++;
                    start++;
                }
            }
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};