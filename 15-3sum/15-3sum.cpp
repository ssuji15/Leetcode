class Solution {
public:
   
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1, k=nums.size()-1;j<k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};
