class Solution {
public:
    vector<vector<int>> result;
    
    void swap(int i, int j, vector<int> &nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void solve(int idx, vector<int> nums) {
        
        if(idx == nums.size()) {
            result.push_back(nums);
            return ;
        }

        for(int i=idx;i<nums.size();i++) {
            swap(idx, i, nums);
            solve(idx+1, nums);
            swap(idx, i, nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return result;
    }
};

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2
    
    
    
    