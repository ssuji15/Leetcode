class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,prod=1;
        for(int i=0,j=0;i<nums.size();i++) {
            prod = prod * nums[i];
            
            while(j<=i && prod >= k) {
                prod = prod / nums[j];
                j++;
            }
            
            if(prod < k) {
                ans += (i-j+1);
            }
        }
        return ans;
    }
};