class Solution {
public:
    void solve(int idx, int target, vector<int> &temp, vector<vector<int>> &result, vector<vector<bool>> &visited, vector<int> &candidates) {
        
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        
        if(target < 0 || idx == candidates.size()) return;
    
        for(int i=idx;i<candidates.size();i++) {
            temp.push_back(candidates[i]);
            solve(i, target-candidates[i], temp, result, visited, candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> temp;
        vector<vector<bool>> visited(candidates.size(), vector<bool>(target+1, false));
        solve(0,target,temp,result, visited, candidates);
        return result;
    }
};