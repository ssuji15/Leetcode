class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProd(nums.size());
        vector<int> rightProd(nums.size());
        vector<int> result(nums.size());
        int prod = 1;
        
        for(int i=0;i<nums.size();i++) {
            prod *= nums[i];
            leftProd[i] = prod;
        }
        
        prod = 1;
        for(int i=nums.size()-1;i>=0;i--) {
            prod *= nums[i];
            rightProd[i] = prod;
        }
        
        for(int i=0;i<nums.size();i++) {
            int prod = 1;
            if(i-1 >= 0) {
                prod = prod * leftProd[i-1];
            }
            if(i+1 < nums.size()) {
                prod = prod * rightProd[i+1];
            }
            result[i] = prod;
        }
        
        return result;
    }
};