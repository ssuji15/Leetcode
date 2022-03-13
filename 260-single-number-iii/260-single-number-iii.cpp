class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long diff = 0;
        for(int i=0;i<nums.size();i++) {
             diff = diff ^ nums[i];
        }
        
        diff &= -diff;
        cout<<diff<<endl;
        vector<int> result = {0,0};
        
        for(int i=0;i<nums.size();i++) {
            if((nums[i] & diff) == 0) {
                result[0] ^= nums[i];
            }
            else {
                result[1] ^= nums[i];
            }
        }
        return result;
        
    }
};