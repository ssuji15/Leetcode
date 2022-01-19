class Solution {
public:
    vector<vector<int>> result;
    void solve(int start, int end, int k, vector<int> nums) {
        
        if(k==0) {
            result.push_back(nums);
            return;
        }
        
        for(int i=start; i<=end;i++) {
            nums.push_back(i);
            solve(i+1, end, k-1, nums);
            nums.pop_back();
        }
        
        return;
    } 
    vector<vector<int>> combine(int n, int k) {
        
        solve(1,n,k, {});
        
        return result;
    }
};

// 1 2 3 4
// 1 2 3
// 1 2 4
// 1 3 4
// 2 3 4    