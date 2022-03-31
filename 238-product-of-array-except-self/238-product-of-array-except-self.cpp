class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = nums[0], right = nums[n-1];
        vector<int> result(n);
        result[0] = 1;
        for(int i=1;i<n;i++) {
            result[i] = left;
            left *= nums[i];
        }
        
        for(int i=n-2;i>=0;i--) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};