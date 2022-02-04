class Solution {
public:
    vector<vector<int>> result;
    void swap(int i, int j, vector<int> &nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void permute(int idx, vector<int> nums) {

        if(idx == nums.size()) {
            result.push_back(nums);
            return ;
        }
        
        for(int i=idx;i<nums.size();i++) {
            if(i != idx && nums[i] == nums[idx]) continue;
            swap(idx, i, nums);
            permute(idx+1, nums);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        result = {};
        permute(0,nums);
        return result;
    }
};


    