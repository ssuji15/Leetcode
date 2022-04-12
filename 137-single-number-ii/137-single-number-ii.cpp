class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++) {
            int sum = 0;
            for(int j=0;j<nums.size();j++) {
                if(nums[j] & (1<<i)) sum++;
            }
            sum = sum % 3;
            
            if(sum == 1) {
                ans = (ans | (1<<i));
            }
        }
        return ans;
    }
};
